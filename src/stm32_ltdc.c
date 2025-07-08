// SPDX-FileCopyrightText: 2024 Ledger SAS
// SPDX-License-Identifier: Apache-2.0

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <stdatomic.h>
#include <stdio.h>


#include <uapi.h>
#include <lcd/lcd.h>

#include "stm32_ltdc_defs.h"
#include "stm32_ltdc_priv.h"

#define LTDC_ID "[ltdc]"
#define print(fmt, ...) \
	printf(LTDC_ID " " fmt, ##__VA_ARGS__)

#define LTDC_PLANEn_OFFSET(n) ((n) * 0x80UL)

static inline int __stm32_ltdc_map(stm32_ltdc_device_t *ltdc)
{
    int ret = -1;
    devh_t handle;
    enum Status status;
    atomic_bool not_mapped = ATOMIC_VAR_INIT(false);

    if (unlikely(!atomic_compare_exchange_strong(&ltdc->mapped, &not_mapped, true))) {
        /* i.e. already mapped, return with no error */
        ret = 0;
        goto err;
    }


    /* Fixme: wrap these in libshield */
    status = sys_get_device_handle(ltdc->dev.id);
    if (status != STATUS_OK) {
        goto err;
    }
    copy_to_user((uint8_t*)&handle, sizeof(devh_t));
    if (sys_map_dev(handle) == STATUS_OK) {
        ret = 0;
    }

err:
    return ret;
}

static inline int __stm32_ltdc_unmap(stm32_ltdc_device_t *ltdc)
{
    int ret = -1;
    devh_t handle;
    enum Status status;
    atomic_bool mapped = ATOMIC_VAR_INIT(true);

    if (unlikely(!atomic_compare_exchange_strong(&ltdc->mapped, &mapped, false))) {
        /* i.e. already unmapped, return with no error */
        ret = 0;
        goto err;
    }

    /* Fixme: wrap these in libshield */
    status = sys_get_device_handle(ltdc->dev.id);
    if (status != STATUS_OK) {
        goto err;
    }
    copy_to_user((uint8_t*)&handle, sizeof(devh_t));
    if (sys_unmap_dev(handle) == STATUS_OK) {
        ret = 0;
    }

err:
    return ret;
}

/**
 * @brief Program LTDC timings
 *
 * The LTDC programmable synchronous timings are the following:
 *
 * • HSYNC and VSYNC width: horizontal and vertical synchronization width, configured by
 * programming a value of HSYNC width - 1 and VSYNC width - 1 in the LTDC_SSCR
 * register
 *
 * • HBP and VBP: horizontal and vertical synchronization back porch width, configured by
 * programming the accumulated value HSYNC width + HBP - 1 and the accumulated
 * value VSYNC width + VBP - 1 in the LTDC_BPCR register.
 *
 * • Active width and active height: the active width and active height are configured by
 * programming the accumulated value HSYNC width + HBP + active width - 1 and the
 * accumulated value VSYNC width + VBP + active height - 1 in the LTDC_AWCR
 * register.
 *
 * • Total width: the total width is configured by programming the accumulated value
 * HSYNC width + HBP + active width + HFP - 1 in the LTDC_TWCR register. The HFP is
 * the horizontal front porch period.
 *
 * • Total height: the total height is configured by programming the accumulated value
 * VSYNC height + VBP + active height + VFP - 1 in the LTDC_TWCR register. The VFP
 * is the vertical front porch period.
 */
static inline void stm32_ltdc_configure_videomode(stm32_ltdc_device_t *ltdc)
{
    const devinfo_t *dev = &ltdc->dev;
    const videomode_t *mode = &ltdc->videomode;
    /* Horizontal Sync Width == HSYNC - 1 */
    uint32_t hsw = mode->hsync_len - 1;
    /* Vertical Sync Height == VSYNC - 1 */
    uint32_t vsh = mode->vsync_len - 1;
    /* Accumulated Horizontal Back Porch == HSYNC + HBP - 1 */
    uint32_t ahbp = hsw + mode->hback_porch;
    /* Accumulated Vertical Back Porch == VSYNC + VBP - 1 */
    uint32_t avbp = vsh + mode->vback_porch;
    /* Accumulated Active Width == HSYNC + HBP + HACTIVE - 1 */
    uint32_t aaw = ahbp + mode->hactive;
    /* Accumulated Active Height == VSYNC + VBP + VACTIVE - 1 */
    uint32_t aah = avbp + mode->vactive;
    /* Total Width == HSYNC + HBP + HACTIVE + HFP - 1 */
    uint32_t totalw = aaw + mode->hfront_porch;
    /* Total Height == VSYNC + VBP + VACTIVE + VFP - 1 */
    uint32_t totalh = aah + mode->vfront_porch;

    stm32_ltdc_register_write(
        dev, LTDC_SSCR_REG, ((hsw << LTDC_SSCR_HSW_SHIFT) & LTDC_SSCR_HSW_MASK)
                          | ((vsh << LTDC_SSCR_VSH_SHIFT) & LTDC_SSCR_VSH_MASK)
    );

    stm32_ltdc_register_write(
        dev, LTDC_BPCR_REG, ((ahbp << LTDC_BPCR_AHBP_SHIFT) & LTDC_BPCR_AHBP_MASK)
                          | ((avbp << LTDC_BPCR_AVBP_SHIFT) & LTDC_BPCR_AVBP_MASK)
    );

    stm32_ltdc_register_write(
        dev, LTDC_AWCR_REG, ((aaw << LTDC_AWCR_AAW_SHIFT) & LTDC_AWCR_AAW_MASK)
                          | ((aah << LTDC_AWCR_AAH_SHIFT) & LTDC_AWCR_AAH_MASK)
    );

    stm32_ltdc_register_write(
        dev, LTDC_TWCR_REG, ((totalw << LTDC_TWCR_TOTALW_SHIFT) & LTDC_TWCR_TOTALW_MASK)
                          | ((totalh << LTDC_TWCR_TOTALH_SHIFT) & LTDC_TWCR_TOTALH_MASK)
    );

}

static inline void stm32_ltdc_configure_clkpol(stm32_ltdc_device_t *ltdc)
{
    const devinfo_t *dev = &ltdc->dev;
    uint32_t gcr = stm32_ltdc_register_read(dev, LTDC_GCR_REG);

    gcr |= /* LTDC_GCR_DEPOL |*/ LTDC_GCR_PCPOL | LTDC_GCR_VSPOL | LTDC_GCR_HSPOL;
    stm32_ltdc_register_write(dev, LTDC_GCR_REG, gcr);
}

/*
 * XXX:
 *  Hardcoded
 */

#define LTDC_PXL_FORMAT_ARGB8888 0UL
#define LTDC_PXL_FORMAT_RGB888   1UL
#define LTDC_PXL_FORMAT_RGB565   2UL
#define LTDC_PXL_FORMAT_ARGB1555 3UL
#define LTDC_PXL_FORMAT_ARGB4444 4UL
#define LTDC_PXL_FORMAT_L8       5UL
#define LTDC_PXL_FORMAT_AL44     6UL
#define LTDC_PXL_FORMAT_AL88     7UL

static inline void stm32_ltdc_configure_primary_plane(stm32_ltdc_device_t *ltdc)
{
    const devinfo_t *dev = &ltdc->dev;
    const videomode_t *mode = &ltdc->videomode;
    /* XXX:
     *  layer full frame (i.e. [0;0] to [480;800] inside the active area)
     *  Add accumulated BP + 1 offset
     */
    uint32_t hpos[2] = {
        mode->hsync_len + mode->hback_porch,
        mode->hsync_len + mode->hback_porch + mode->hactive - 1,
    };
    uint32_t vpos[2] = {
        mode->vsync_len + mode->vback_porch,
        mode->vsync_len + mode->vback_porch + mode->vactive - 1,
    };
    uint32_t pxl_format = LTDC_PXL_FORMAT_RGB565;
    uint32_t pitch = mode->hactive * 2; /* pitch in bytes => pixel width * byte per pixel  */
    uint32_t lines = mode->vactive;

    /* no color blending, keyring or CLUT based color space conversion */

    /* Horizontal Window pos */
    stm32_ltdc_register_write(
        dev, LTDC_L1WHPCR_REG, ((hpos[0] << LTDC_L1WHPCR_WHSTPOS_SHIFT) & LTDC_L1WHPCR_WHSTPOS_MASK)
                             | ((hpos[1] << LTDC_L1WHPCR_WHSPPOS_SHIFT) & LTDC_L1WHPCR_WHSPPOS_MASK)
    );

    /* Vertical Window pos */
    stm32_ltdc_register_write(
        dev, LTDC_L1WVPCR_REG, ((vpos[0] << LTDC_L1WVPCR_WVSTPOS_SHIFT) & LTDC_L1WVPCR_WVSTPOS_MASK)
                             | ((vpos[1] << LTDC_L1WVPCR_WVSPPOS_SHIFT) & LTDC_L1WVPCR_WVSPPOS_MASK)
    );

    /* pixel format */
    stm32_ltdc_register_write(dev, LTDC_L1PFCR_REG, (pxl_format << LTDC_L1PFCR_PF_SHIFT) & LTDC_L1PFCR_PF_MASK);
    /*
     * FB line size
     *
     * XXX:
     *  ST black magic here, cf RM0456 Reference manual p1726.
     *
     *  > CFBLL[12:0]: Color frame buffer line length
     *  > These bits define the length of one line of pixels in bytes + 3.
     *  > The line length is computed as follows:
     *  > active high width * number of bytes per pixel + 3.
     */
    stm32_ltdc_register_write(
        dev, LTDC_L1CFBLR_REG, ((pitch << LTDC_L1CFBLR_CFBP_SHIFT) & LTDC_L1CFBLR_CFBP_MASK)
                             | (((pitch + 3) << LTDC_L1CFBLR_CFBLL_SHIFT) & LTDC_L1CFBLR_CFBLL_MASK)
    );

    /* FB nr lines */
    stm32_ltdc_register_write(dev, LTDC_L1CFBLNR_REG, (lines << LTDC_L1CFBLNR_CFBLNBR_SHIFT) & LTDC_L1CFBLNR_CFBLNBR_MASK);

    /*
     * Frame buffer address, plane activation and LTDC start-up are done by upper layer,
     * i.e. mipi and/or graphical backend (e.g. lvgl).
     *
     * TODO, we may provide a generic framebuffer and layout API, for primary plane and (windowed) overlay.
     */
}

int stm32_ltdc_map(const uint8_t id)
{
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(id);

    if (unlikely(ltdc == NULL)) {
        return -1;
    }

    return __stm32_ltdc_map(ltdc);
}

int stm32_ltdc_unmap(const uint8_t id)
{
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(id);

    if (unlikely(ltdc == NULL)) {
        return -1;
    }

    return __stm32_ltdc_unmap(ltdc);
}

int stm32_ltdc_enable(const uint8_t lcd_id)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;
    uint32_t gcr;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    gcr = stm32_ltdc_register_read(dev, LTDC_GCR_REG);
    gcr |= LTDC_GCR_LTDCEN;
    stm32_ltdc_register_write(dev, LTDC_GCR_REG, gcr);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_disable(const uint8_t lcd_id)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;
    uint32_t gcr;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    gcr = stm32_ltdc_register_read(dev, LTDC_GCR_REG);
    gcr &= ~LTDC_GCR_LTDCEN;
    stm32_ltdc_register_write(dev, LTDC_GCR_REG, gcr);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_plane_enable(const uint8_t lcd_id, const uint8_t plane_id)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;
    uint32_t lcr;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    /* XXX */
    if (unlikely(plane_id > 1)) {
        print("[Error] plane id %u out of range\n", plane_id);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    lcr = stm32_ltdc_register_read(dev, LTDC_L1CR_REG + LTDC_PLANEn_OFFSET(plane_id));
    lcr |= LTDC_L1CR_LEN;
    stm32_ltdc_register_write(dev, LTDC_L1CR_REG + LTDC_PLANEn_OFFSET(plane_id), lcr);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_plane_disable(const uint8_t lcd_id, const uint8_t plane_id)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;
    uint32_t lcr;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    /* XXX */
    if (unlikely(plane_id > 1)) {
        print("[Error] plane id %u out of range\n", plane_id);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    lcr = stm32_ltdc_register_read(dev, LTDC_L1CR_REG + LTDC_PLANEn_OFFSET(plane_id));
    lcr &= ~LTDC_L1CR_LEN;
    stm32_ltdc_register_write(dev, LTDC_L1CR_REG + LTDC_PLANEn_OFFSET(plane_id), lcr);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_plane_set_fbaddr(const uint8_t lcd_id, const uint8_t plane_id, uint32_t fbaddr)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    /* XXX */
    if (unlikely(plane_id > 1)) {
        print("[Error] plane id %u out of range\n", plane_id);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    stm32_ltdc_register_write(dev, LTDC_L1CFBAR_REG + LTDC_PLANEn_OFFSET(plane_id), fbaddr);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_shadow_load(const uint8_t lcd_id, lcd_shadow_load_mode_t mode)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_load(&ltdc->probed))) {
        print("[Error] ltdc id %u not probbed\n", lcd_id);
        goto err;
    }

    if (unlikely(mode >= LCD_SHADOW_LOAD_LAST)) {
        print("[Error] invalid shadow load mode %d\n", mode);
        goto err;
    }

    /*
     * we do not handle unmap for now.
     * map is done only if not mapped yet.
     * One may manages this with ref counting ?!?
     */
#if 0
    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }
#endif

    stm32_ltdc_register_write(dev, LTDC_SRCR_REG, mode == LCD_SHADOW_LOAD_VBLANK ? LTDC_SRCR_VBR : LTDC_SRCR_IMR);
    ret = 0;

err:
    return ret;
}

int stm32_ltdc_probe(const uint8_t lcd_id)
{
    int ret = -1;
    stm32_ltdc_device_t *ltdc = stm32_ltdc_get_device(lcd_id);
    const devinfo_t *dev = NULL;
    atomic_bool not_probed = ATOMIC_VAR_INIT(false);

    if (unlikely(ltdc == NULL)) {
        print("[Error] invalid ltdc id %u \n", lcd_id);
        goto err;
    }

    dev = &ltdc->dev;

    if (unlikely(!atomic_compare_exchange_strong(&ltdc->probed, &not_probed, true))) {
        print("[Error] device %lx already probed\n", dev->id);
        goto err;
    }

    ret = __stm32_ltdc_map(ltdc);
    if (unlikely(ret)) {
        print("[Error] failed to map device %lx\n", dev->id);
        goto err;
    }

    stm32_ltdc_configure_videomode(ltdc);
    stm32_ltdc_configure_clkpol(ltdc);

    /*
     * No sync interrupt, simple double buffering w/ whole refresh in lvgl and shadow loading
     * There is multiple other solution to optimize rendering.
     *  e.g.
     * LVGL can handled DMA2D (GPU2D ?!?) which can be used to compose in back buffer.
     * LTDC can trig GPDMA transfer on scanline interrupt to copy back buffer (if ready) to front buffer.
     * (programmable watermark, might be configure to the last line to act as a vblank interrupt).
     * GPDMA end of transfer IQR set LVGL ready to refresh flag.
     *
     * GPDMA throughput ?!?
     *
     * In a double buffering scenario, for lower latency, we may use GPDMA as LTDC has no
     * trigger to DMA2D (and we may need this device for cam).
     */

    /* no bgcolor ? */

    /* configure primary layer */

    /* do we need complex plane allocation ? (like in linux drm layer w/ pixel transform etc.) */
    stm32_ltdc_configure_primary_plane(ltdc);

    /* no overlay ? (cam ?) */

err:
    return ret;
}

/* LCD API aliased symbols */
int lcd_probe(const uint8_t lcd_id) __attribute__((alias("stm32_ltdc_probe")));
int lcd_map(const uint8_t id) __attribute__((alias("stm32_ltdc_map")));
int lcd_unmap(const uint8_t id) __attribute__((alias("stm32_ltdc_unmap")));
int lcd_enable(const uint8_t lcd_id) __attribute__((alias("stm32_ltdc_enable")));
int lcd_disable(const uint8_t lcd_id) __attribute__((alias("stm32_ltdc_disable")));
int lcd_plane_enable(const uint8_t lcd_id, const uint8_t plane_id) __attribute__((alias("stm32_ltdc_plane_enable")));
int lcd_plane_disable(const uint8_t lcd_id, const uint8_t plane_id) __attribute__((alias("stm32_ltdc_plane_disable")));
int lcd_plane_set_fbaddr(const uint8_t lcd_id, const uint8_t plane_id, uint32_t fbaddr) __attribute__((alias("stm32_ltdc_plane_set_fbaddr")));
int lcd_shadow_load(const uint8_t lcd_id, lcd_shadow_load_mode_t mode) __attribute__((alias("stm32_ltdc_shadow_load")));
