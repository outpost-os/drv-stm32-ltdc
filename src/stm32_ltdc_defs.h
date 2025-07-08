// SPDX-License-Identifier: Apache-2.0

/*
 * Copyright 2023 Ledger SAS
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * XXX:
 *  !!!! Generated header, DO NOT EDIT !!!!
 */
#ifndef __STM32U599_LTDC_DEFS_H
#define __STM32U599_LTDC_DEFS_H

#include <assert.h>
#include <inttypes.h>

/**
 *  @brief LTDC SSCR register
 *
 * LTDC synchronization size configuration register
 *
 *  @note offset: 0x8UL
 *        width:  32 bits
 */
#define LTDC_SSCR_REG  0x8UL

/**
 * @brief LTDC SSCR VSH field
 *
 * vertical synchronization height (in units of horizontal scan line) These bits define the vertical Synchronization height minus 1. It represents the number of horizontal synchronization lines.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_SSCR_VSH_SHIFT 0x0UL
#define LTDC_SSCR_VSH_MASK (((1ULL << 11) - 1) << LTDC_SSCR_VSH_SHIFT)
/**
 * @brief LTDC SSCR HSW field
 *
 * horizontal synchronization width (in units of pixel clock period) These bits define the number of Horizontal Synchronization pixel minus 1.
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_SSCR_HSW_SHIFT 0x10UL
#define LTDC_SSCR_HSW_MASK (((1ULL << 12) - 1) << LTDC_SSCR_HSW_SHIFT)


struct ltdc_sscr {
    uint32_t vsh:11;
    uint32_t reserved0:5;
    uint32_t hsw:12;
    };

typedef struct ltdc_sscr ltdc_sscr_t;
static_assert(sizeof(ltdc_sscr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC BPCR register
 *
 * LTDC back porch configuration register
 *
 *  @note offset: 0xcUL
 *        width:  32 bits
 */
#define LTDC_BPCR_REG  0xcUL

/**
 * @brief LTDC BPCR AVBP field
 *
 * accumulated Vertical back porch (in units of horizontal scan line) These bits define the accumulated vertical back porch width that includes the vertical synchronization and vertical back porch lines minus 1. The vertical back porch is the number of horizontal scan lines at a start of frame to the start of the first active scan line of the next frame.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_BPCR_AVBP_SHIFT 0x0UL
#define LTDC_BPCR_AVBP_MASK (((1ULL << 11) - 1) << LTDC_BPCR_AVBP_SHIFT)
/**
 * @brief LTDC BPCR AHBP field
 *
 * accumulated horizontal back porch (in units of pixel clock period) These bits define the accumulated horizontal back porch width that includes the horizontal synchronization and horizontal back porch pixels minus 1. The horizontal back porch is the period between horizontal synchronization going inactive and the start of the active display part of the next scan line.
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_BPCR_AHBP_SHIFT 0x10UL
#define LTDC_BPCR_AHBP_MASK (((1ULL << 12) - 1) << LTDC_BPCR_AHBP_SHIFT)


struct ltdc_bpcr {
    uint32_t avbp:11;
    uint32_t reserved0:5;
    uint32_t ahbp:12;
    };

typedef struct ltdc_bpcr ltdc_bpcr_t;
static_assert(sizeof(ltdc_bpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC AWCR register
 *
 * LTDC active width configuration register
 *
 *  @note offset: 0x10UL
 *        width:  32 bits
 */
#define LTDC_AWCR_REG  0x10UL

/**
 * @brief LTDC AWCR AAH field
 *
 * accumulated active height (in units of horizontal scan line) These bits define the accumulated height which includes the vertical synchronization, vertical back porch and the active height lines minus 1. The active height is the number of active lines in the panel. Refer to device datasheet for maximum active height supported following maximum pixel clock.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_AWCR_AAH_SHIFT 0x0UL
#define LTDC_AWCR_AAH_MASK (((1ULL << 11) - 1) << LTDC_AWCR_AAH_SHIFT)
/**
 * @brief LTDC AWCR AAW field
 *
 * accumulated active width (in units of pixel clock period) These bits define the accumulated active width which includes the horizontal synchronization, horizontal back porch and active pixels minus 1. The active width is the number of pixels in active display area of the panel scan line. Refer to device datasheet for maximum active width supported following maximum pixel clock.
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_AWCR_AAW_SHIFT 0x10UL
#define LTDC_AWCR_AAW_MASK (((1ULL << 12) - 1) << LTDC_AWCR_AAW_SHIFT)


struct ltdc_awcr {
    uint32_t aah:11;
    uint32_t reserved0:5;
    uint32_t aaw:12;
    };

typedef struct ltdc_awcr ltdc_awcr_t;
static_assert(sizeof(ltdc_awcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC TWCR register
 *
 * LTDC total width configuration register
 *
 *  @note offset: 0x14UL
 *        width:  32 bits
 */
#define LTDC_TWCR_REG  0x14UL

/**
 * @brief LTDC TWCR TOTALH field
 *
 * total height (in units of horizontal scan line) These bits defines the accumulated height which includes the vertical synchronization, vertical back porch, the active height and vertical front porch height lines minus 1.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_TWCR_TOTALH_SHIFT 0x0UL
#define LTDC_TWCR_TOTALH_MASK (((1ULL << 11) - 1) << LTDC_TWCR_TOTALH_SHIFT)
/**
 * @brief LTDC TWCR TOTALW field
 *
 * total width (in units of pixel clock period) These bits defines the accumulated total width which includes the horizontal synchronization, horizontal back porch, active width and horizontal front porch pixels minus 1.
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_TWCR_TOTALW_SHIFT 0x10UL
#define LTDC_TWCR_TOTALW_MASK (((1ULL << 12) - 1) << LTDC_TWCR_TOTALW_SHIFT)


struct ltdc_twcr {
    uint32_t totalh:11;
    uint32_t reserved0:5;
    uint32_t totalw:12;
    };

typedef struct ltdc_twcr ltdc_twcr_t;
static_assert(sizeof(ltdc_twcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC GCR register
 *
 * LTDC global control register
 *
 *  @note offset: 0x18UL
 *        width:  32 bits
 */
#define LTDC_GCR_REG  0x18UL

/**
 * @brief LTDC GCR LTDCEN field
 *
 * LCD-TFT controller enable This bit is set and cleared by software.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_LTDCEN (1UL << 0x0UL)
#define LTDC_GCR_LTDCEN_SHIFT 0x0UL
#define LTDC_GCR_LTDCEN_MASK (((1ULL << 1) - 1) << LTDC_GCR_LTDCEN_SHIFT)
/**
 * @brief LTDC GCR DBW field
 *
 * dither blue width These bits return the dither blue bits.
 *
 * @note offset: 0x4UL
 *       width:  3
 *       access: read-only
 */
#define LTDC_GCR_DBW_SHIFT 0x4UL
#define LTDC_GCR_DBW_MASK (((1ULL << 3) - 1) << LTDC_GCR_DBW_SHIFT)
/**
 * @brief LTDC GCR DGW field
 *
 * dither green width These bits return the dither green bits.
 *
 * @note offset: 0x8UL
 *       width:  3
 *       access: read-only
 */
#define LTDC_GCR_DGW_SHIFT 0x8UL
#define LTDC_GCR_DGW_MASK (((1ULL << 3) - 1) << LTDC_GCR_DGW_SHIFT)
/**
 * @brief LTDC GCR DRW field
 *
 * dither red width These bits return the Dither Red Bits.
 *
 * @note offset: 0xcUL
 *       width:  3
 *       access: read-only
 */
#define LTDC_GCR_DRW_SHIFT 0xcUL
#define LTDC_GCR_DRW_MASK (((1ULL << 3) - 1) << LTDC_GCR_DRW_SHIFT)
/**
 * @brief LTDC GCR DEN field
 *
 * dither enable This bit is set and cleared by software.
 *
 * @note offset: 0x10UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_DEN (1UL << 0x10UL)
#define LTDC_GCR_DEN_SHIFT 0x10UL
#define LTDC_GCR_DEN_MASK (((1ULL << 1) - 1) << LTDC_GCR_DEN_SHIFT)
/**
 * @brief LTDC GCR PCPOL field
 *
 * pixel clock polarity This bit is set and cleared by software.
 *
 * @note offset: 0x1cUL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_PCPOL (1UL << 0x1cUL)
#define LTDC_GCR_PCPOL_SHIFT 0x1cUL
#define LTDC_GCR_PCPOL_MASK (((1ULL << 1) - 1) << LTDC_GCR_PCPOL_SHIFT)
/**
 * @brief LTDC GCR DEPOL field
 *
 * not data enable polarity This bit is set and cleared by software.
 *
 * @note offset: 0x1dUL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_DEPOL (1UL << 0x1dUL)
#define LTDC_GCR_DEPOL_SHIFT 0x1dUL
#define LTDC_GCR_DEPOL_MASK (((1ULL << 1) - 1) << LTDC_GCR_DEPOL_SHIFT)
/**
 * @brief LTDC GCR VSPOL field
 *
 * vertical synchronization polarity This bit is set and cleared by software.
 *
 * @note offset: 0x1eUL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_VSPOL (1UL << 0x1eUL)
#define LTDC_GCR_VSPOL_SHIFT 0x1eUL
#define LTDC_GCR_VSPOL_MASK (((1ULL << 1) - 1) << LTDC_GCR_VSPOL_SHIFT)
/**
 * @brief LTDC GCR HSPOL field
 *
 * horizontal synchronization polarity This bit is set and cleared by software.
 *
 * @note offset: 0x1fUL
 *       width:  1
 *       access: read-write
 */
#define LTDC_GCR_HSPOL (1UL << 0x1fUL)
#define LTDC_GCR_HSPOL_SHIFT 0x1fUL
#define LTDC_GCR_HSPOL_MASK (((1ULL << 1) - 1) << LTDC_GCR_HSPOL_SHIFT)


struct ltdc_gcr {
    uint32_t ltdcen:1;
    uint32_t reserved0:3;
    uint32_t dbw:3;
    uint32_t reserved1:1;
    uint32_t dgw:3;
    uint32_t reserved2:1;
    uint32_t drw:3;
    uint32_t reserved3:1;
    uint32_t den:1;
    uint32_t reserved4:11;
    uint32_t pcpol:1;
    uint32_t depol:1;
    uint32_t vspol:1;
    uint32_t hspol:1;
    };

typedef struct ltdc_gcr ltdc_gcr_t;
static_assert(sizeof(ltdc_gcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC SRCR register
 *
 * LTDC shadow reload configuration register
 *
 *  @note offset: 0x24UL
 *        width:  32 bits
 */
#define LTDC_SRCR_REG  0x24UL

/**
 * @brief LTDC SRCR IMR field
 *
 * immediate reload This bit is set by software and cleared only by hardware after reload.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_SRCR_IMR (1UL << 0x0UL)
#define LTDC_SRCR_IMR_SHIFT 0x0UL
#define LTDC_SRCR_IMR_MASK (((1ULL << 1) - 1) << LTDC_SRCR_IMR_SHIFT)
/**
 * @brief LTDC SRCR VBR field
 *
 * vertical blanking reload This bit is set by software and cleared only by hardware after reload (it cannot be cleared through register write once it is set).
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_SRCR_VBR (1UL << 0x1UL)
#define LTDC_SRCR_VBR_SHIFT 0x1UL
#define LTDC_SRCR_VBR_MASK (((1ULL << 1) - 1) << LTDC_SRCR_VBR_SHIFT)


struct ltdc_srcr {
    uint32_t imr:1;
    uint32_t vbr:1;
    };

typedef struct ltdc_srcr ltdc_srcr_t;
static_assert(sizeof(ltdc_srcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC BCCR register
 *
 * LTDC background color configuration register
 *
 *  @note offset: 0x2cUL
 *        width:  32 bits
 */
#define LTDC_BCCR_REG  0x2cUL

/**
 * @brief LTDC BCCR BCBLUE field
 *
 * background color blue value These bits configure the background blue value.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_BCCR_BCBLUE_SHIFT 0x0UL
#define LTDC_BCCR_BCBLUE_MASK (((1ULL << 8) - 1) << LTDC_BCCR_BCBLUE_SHIFT)
/**
 * @brief LTDC BCCR BCGREEN field
 *
 * background color green value These bits configure the background green value.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_BCCR_BCGREEN_SHIFT 0x8UL
#define LTDC_BCCR_BCGREEN_MASK (((1ULL << 8) - 1) << LTDC_BCCR_BCGREEN_SHIFT)
/**
 * @brief LTDC BCCR BCRED field
 *
 * background color red value These bits configure the background red value.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_BCCR_BCRED_SHIFT 0x10UL
#define LTDC_BCCR_BCRED_MASK (((1ULL << 8) - 1) << LTDC_BCCR_BCRED_SHIFT)


struct ltdc_bccr {
    uint32_t bcblue:8;
    uint32_t bcgreen:8;
    uint32_t bcred:8;
    };

typedef struct ltdc_bccr ltdc_bccr_t;
static_assert(sizeof(ltdc_bccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC IER register
 *
 * LTDC interrupt enable register
 *
 *  @note offset: 0x34UL
 *        width:  32 bits
 */
#define LTDC_IER_REG  0x34UL

/**
 * @brief LTDC IER LIE field
 *
 * line interrupt enable This bit is set and cleared by software.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_IER_LIE (1UL << 0x0UL)
#define LTDC_IER_LIE_SHIFT 0x0UL
#define LTDC_IER_LIE_MASK (((1ULL << 1) - 1) << LTDC_IER_LIE_SHIFT)
/**
 * @brief LTDC IER FUIE field
 *
 * FIFO underrun interrupt enable This bit is set and cleared by software.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_IER_FUIE (1UL << 0x1UL)
#define LTDC_IER_FUIE_SHIFT 0x1UL
#define LTDC_IER_FUIE_MASK (((1ULL << 1) - 1) << LTDC_IER_FUIE_SHIFT)
/**
 * @brief LTDC IER TERRIE field
 *
 * transfer error interrupt enable This bit is set and cleared by software.
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_IER_TERRIE (1UL << 0x2UL)
#define LTDC_IER_TERRIE_SHIFT 0x2UL
#define LTDC_IER_TERRIE_MASK (((1ULL << 1) - 1) << LTDC_IER_TERRIE_SHIFT)
/**
 * @brief LTDC IER RRIE field
 *
 * register reload interrupt enable This bit is set and cleared by software.
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_IER_RRIE (1UL << 0x3UL)
#define LTDC_IER_RRIE_SHIFT 0x3UL
#define LTDC_IER_RRIE_MASK (((1ULL << 1) - 1) << LTDC_IER_RRIE_SHIFT)


struct ltdc_ier {
    uint32_t lie:1;
    uint32_t fuie:1;
    uint32_t terrie:1;
    uint32_t rrie:1;
    };

typedef struct ltdc_ier ltdc_ier_t;
static_assert(sizeof(ltdc_ier_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC ISR register
 *
 * LTDC interrupt status register
 *
 *  @note offset: 0x38UL
 *        width:  32 bits
 */
#define LTDC_ISR_REG  0x38UL

/**
 * @brief LTDC ISR LIF field
 *
 * line interrupt flag
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_ISR_LIF (1UL << 0x0UL)
#define LTDC_ISR_LIF_SHIFT 0x0UL
#define LTDC_ISR_LIF_MASK (((1ULL << 1) - 1) << LTDC_ISR_LIF_SHIFT)
/**
 * @brief LTDC ISR FUIF field
 *
 * FIFO underrun interrupt flag
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_ISR_FUIF (1UL << 0x1UL)
#define LTDC_ISR_FUIF_SHIFT 0x1UL
#define LTDC_ISR_FUIF_MASK (((1ULL << 1) - 1) << LTDC_ISR_FUIF_SHIFT)
/**
 * @brief LTDC ISR TERRIF field
 *
 * transfer error interrupt flag
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_ISR_TERRIF (1UL << 0x2UL)
#define LTDC_ISR_TERRIF_SHIFT 0x2UL
#define LTDC_ISR_TERRIF_MASK (((1ULL << 1) - 1) << LTDC_ISR_TERRIF_SHIFT)
/**
 * @brief LTDC ISR RRIF field
 *
 * register reload interrupt flag
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_ISR_RRIF (1UL << 0x3UL)
#define LTDC_ISR_RRIF_SHIFT 0x3UL
#define LTDC_ISR_RRIF_MASK (((1ULL << 1) - 1) << LTDC_ISR_RRIF_SHIFT)


struct ltdc_isr {
    uint32_t lif:1;
    uint32_t fuif:1;
    uint32_t terrif:1;
    uint32_t rrif:1;
    };

typedef struct ltdc_isr ltdc_isr_t;
static_assert(sizeof(ltdc_isr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC ICR register
 *  @note offset: 0x3cUL
 *        width:  32 bits
 */
#define LTDC_ICR_REG  0x3cUL

/**
 * @brief LTDC ICR CLIF field
 *
 * clears the line interrupt flag
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: write-only
 */
#define LTDC_ICR_CLIF (1UL << 0x0UL)
#define LTDC_ICR_CLIF_SHIFT 0x0UL
#define LTDC_ICR_CLIF_MASK (((1ULL << 1) - 1) << LTDC_ICR_CLIF_SHIFT)
/**
 * @brief LTDC ICR CFUIF field
 *
 * clears the FIFO underrun interrupt flag
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: write-only
 */
#define LTDC_ICR_CFUIF (1UL << 0x1UL)
#define LTDC_ICR_CFUIF_SHIFT 0x1UL
#define LTDC_ICR_CFUIF_MASK (((1ULL << 1) - 1) << LTDC_ICR_CFUIF_SHIFT)
/**
 * @brief LTDC ICR CTERRIF field
 *
 * clears the transfer error interrupt flag
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: write-only
 */
#define LTDC_ICR_CTERRIF (1UL << 0x2UL)
#define LTDC_ICR_CTERRIF_SHIFT 0x2UL
#define LTDC_ICR_CTERRIF_MASK (((1ULL << 1) - 1) << LTDC_ICR_CTERRIF_SHIFT)
/**
 * @brief LTDC ICR CRRIF field
 *
 * clears register reload interrupt flag
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: write-only
 */
#define LTDC_ICR_CRRIF (1UL << 0x3UL)
#define LTDC_ICR_CRRIF_SHIFT 0x3UL
#define LTDC_ICR_CRRIF_MASK (((1ULL << 1) - 1) << LTDC_ICR_CRRIF_SHIFT)


struct ltdc_icr {
    uint32_t clif:1;
    uint32_t cfuif:1;
    uint32_t cterrif:1;
    uint32_t crrif:1;
    };

typedef struct ltdc_icr ltdc_icr_t;
static_assert(sizeof(ltdc_icr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC LIPCR register
 *
 * LTDC line interrupt position configuration register
 *
 *  @note offset: 0x40UL
 *        width:  32 bits
 */
#define LTDC_LIPCR_REG  0x40UL

/**
 * @brief LTDC LIPCR LIPOS field
 *
 * line interrupt position These bits configure the line interrupt position.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_LIPCR_LIPOS_SHIFT 0x0UL
#define LTDC_LIPCR_LIPOS_MASK (((1ULL << 11) - 1) << LTDC_LIPCR_LIPOS_SHIFT)


struct ltdc_lipcr {
    uint32_t lipos:11;
    };

typedef struct ltdc_lipcr ltdc_lipcr_t;
static_assert(sizeof(ltdc_lipcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC CPSR register
 *  @note offset: 0x44UL
 *        width:  32 bits
 */
#define LTDC_CPSR_REG  0x44UL

/**
 * @brief LTDC CPSR CYPOS field
 *
 * current Y position These bits return the current Y position.
 *
 * @note offset: 0x0UL
 *       width:  16
 *       access: read-only
 */
#define LTDC_CPSR_CYPOS_SHIFT 0x0UL
#define LTDC_CPSR_CYPOS_MASK (((1ULL << 16) - 1) << LTDC_CPSR_CYPOS_SHIFT)
/**
 * @brief LTDC CPSR CXPOS field
 *
 * current X position These bits return the current X position.
 *
 * @note offset: 0x10UL
 *       width:  16
 *       access: read-only
 */
#define LTDC_CPSR_CXPOS_SHIFT 0x10UL
#define LTDC_CPSR_CXPOS_MASK (((1ULL << 16) - 1) << LTDC_CPSR_CXPOS_SHIFT)


struct ltdc_cpsr {
    uint32_t cypos:16;
    uint32_t cxpos:16;
    };

typedef struct ltdc_cpsr ltdc_cpsr_t;
static_assert(sizeof(ltdc_cpsr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC CDSR register
 *
 * LTDC current display status register
 *
 *  @note offset: 0x48UL
 *        width:  32 bits
 */
#define LTDC_CDSR_REG  0x48UL

/**
 * @brief LTDC CDSR VDES field
 *
 * vertical data enable display status
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_CDSR_VDES (1UL << 0x0UL)
#define LTDC_CDSR_VDES_SHIFT 0x0UL
#define LTDC_CDSR_VDES_MASK (((1ULL << 1) - 1) << LTDC_CDSR_VDES_SHIFT)
/**
 * @brief LTDC CDSR HDES field
 *
 * horizontal data enable display status
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_CDSR_HDES (1UL << 0x1UL)
#define LTDC_CDSR_HDES_SHIFT 0x1UL
#define LTDC_CDSR_HDES_MASK (((1ULL << 1) - 1) << LTDC_CDSR_HDES_SHIFT)
/**
 * @brief LTDC CDSR VSYNCS field
 *
 * vertical synchronization display status
 *
 * @note offset: 0x2UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_CDSR_VSYNCS (1UL << 0x2UL)
#define LTDC_CDSR_VSYNCS_SHIFT 0x2UL
#define LTDC_CDSR_VSYNCS_MASK (((1ULL << 1) - 1) << LTDC_CDSR_VSYNCS_SHIFT)
/**
 * @brief LTDC CDSR HSYNCS field
 *
 * horizontal synchronization display status
 *
 * @note offset: 0x3UL
 *       width:  1
 *       access: read-only
 */
#define LTDC_CDSR_HSYNCS (1UL << 0x3UL)
#define LTDC_CDSR_HSYNCS_SHIFT 0x3UL
#define LTDC_CDSR_HSYNCS_MASK (((1ULL << 1) - 1) << LTDC_CDSR_HSYNCS_SHIFT)


struct ltdc_cdsr {
    uint32_t vdes:1;
    uint32_t hdes:1;
    uint32_t vsyncs:1;
    uint32_t hsyncs:1;
    };

typedef struct ltdc_cdsr ltdc_cdsr_t;
static_assert(sizeof(ltdc_cdsr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CR register
 *  @note offset: 0x84UL
 *        width:  32 bits
 */
#define LTDC_L1CR_REG  0x84UL

/**
 * @brief LTDC L1CR LEN field
 *
 * layer enable This bit is set and cleared by software.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L1CR_LEN (1UL << 0x0UL)
#define LTDC_L1CR_LEN_SHIFT 0x0UL
#define LTDC_L1CR_LEN_MASK (((1ULL << 1) - 1) << LTDC_L1CR_LEN_SHIFT)
/**
 * @brief LTDC L1CR COLKEN field
 *
 * color keying enable This bit is set and cleared by software.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L1CR_COLKEN (1UL << 0x1UL)
#define LTDC_L1CR_COLKEN_SHIFT 0x1UL
#define LTDC_L1CR_COLKEN_MASK (((1ULL << 1) - 1) << LTDC_L1CR_COLKEN_SHIFT)
/**
 * @brief LTDC L1CR CLUTEN field
 *
 * color look-up table enable This bit is set and cleared by software. The CLUT is only meaningful for L8, AL44 and AL88 pixel format. Refer to table (CLUT)
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L1CR_CLUTEN (1UL << 0x4UL)
#define LTDC_L1CR_CLUTEN_SHIFT 0x4UL
#define LTDC_L1CR_CLUTEN_MASK (((1ULL << 1) - 1) << LTDC_L1CR_CLUTEN_SHIFT)


struct ltdc_l1cr {
    uint32_t len:1;
    uint32_t colken:1;
    uint32_t reserved0:2;
    uint32_t cluten:1;
    };

typedef struct ltdc_l1cr ltdc_l1cr_t;
static_assert(sizeof(ltdc_l1cr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1WHPCR register
 *
 * LTDC layer 1 window horizontal position configuration register
 *
 *  @note offset: 0x88UL
 *        width:  32 bits
 */
#define LTDC_L1WHPCR_REG  0x88UL

/**
 * @brief LTDC L1WHPCR WHSTPOS field
 *
 * window horizontal start position These bits configure the first visible pixel of a line of the layer window. WHSTPOS[11:0] must be ≤ AAW[11:0] bits (programmed in LTDC_AWCR register).
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_L1WHPCR_WHSTPOS_SHIFT 0x0UL
#define LTDC_L1WHPCR_WHSTPOS_MASK (((1ULL << 12) - 1) << LTDC_L1WHPCR_WHSTPOS_SHIFT)
/**
 * @brief LTDC L1WHPCR WHSPPOS field
 *
 * window horizontal stop position These bits configure the last visible pixel of a line of the layer window. WHSPPOS[11:0] must be ≥ AHBP[11:0] bits + 1 (programmed in LTDC_BPCR register).
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_L1WHPCR_WHSPPOS_SHIFT 0x10UL
#define LTDC_L1WHPCR_WHSPPOS_MASK (((1ULL << 12) - 1) << LTDC_L1WHPCR_WHSPPOS_SHIFT)


struct ltdc_l1whpcr {
    uint32_t whstpos:12;
    uint32_t reserved0:4;
    uint32_t whsppos:12;
    };

typedef struct ltdc_l1whpcr ltdc_l1whpcr_t;
static_assert(sizeof(ltdc_l1whpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1WVPCR register
 *
 * LTDC layer 1 window vertical position configuration register
 *
 *  @note offset: 0x8cUL
 *        width:  32 bits
 */
#define LTDC_L1WVPCR_REG  0x8cUL

/**
 * @brief LTDC L1WVPCR WVSTPOS field
 *
 * window vertical start position These bits configure the first visible line of the layer window. WVSTPOS[10:0] must be ≤ AAH[10:0] bits (programmed in LTDC_AWCR register).
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L1WVPCR_WVSTPOS_SHIFT 0x0UL
#define LTDC_L1WVPCR_WVSTPOS_MASK (((1ULL << 11) - 1) << LTDC_L1WVPCR_WVSTPOS_SHIFT)
/**
 * @brief LTDC L1WVPCR WVSPPOS field
 *
 * window vertical stop position These bits configure the last visible line of the layer window. WVSPPOS[10:0] must be ≥ AVBP[10:0] bits + 1 (programmed in LTDC_BPCR register).
 *
 * @note offset: 0x10UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L1WVPCR_WVSPPOS_SHIFT 0x10UL
#define LTDC_L1WVPCR_WVSPPOS_MASK (((1ULL << 11) - 1) << LTDC_L1WVPCR_WVSPPOS_SHIFT)


struct ltdc_l1wvpcr {
    uint32_t wvstpos:11;
    uint32_t reserved0:5;
    uint32_t wvsppos:11;
    };

typedef struct ltdc_l1wvpcr ltdc_l1wvpcr_t;
static_assert(sizeof(ltdc_l1wvpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CKCR register
 *
 * LTDC layer 1 color keying configuration register
 *
 *  @note offset: 0x90UL
 *        width:  32 bits
 */
#define LTDC_L1CKCR_REG  0x90UL

/**
 * @brief LTDC L1CKCR CKBLUE field
 *
 * color key blue value
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1CKCR_CKBLUE_SHIFT 0x0UL
#define LTDC_L1CKCR_CKBLUE_MASK (((1ULL << 8) - 1) << LTDC_L1CKCR_CKBLUE_SHIFT)
/**
 * @brief LTDC L1CKCR CKGREEN field
 *
 * color key green value
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1CKCR_CKGREEN_SHIFT 0x8UL
#define LTDC_L1CKCR_CKGREEN_MASK (((1ULL << 8) - 1) << LTDC_L1CKCR_CKGREEN_SHIFT)
/**
 * @brief LTDC L1CKCR CKRED field
 *
 * color key red value
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1CKCR_CKRED_SHIFT 0x10UL
#define LTDC_L1CKCR_CKRED_MASK (((1ULL << 8) - 1) << LTDC_L1CKCR_CKRED_SHIFT)


struct ltdc_l1ckcr {
    uint32_t ckblue:8;
    uint32_t ckgreen:8;
    uint32_t ckred:8;
    };

typedef struct ltdc_l1ckcr ltdc_l1ckcr_t;
static_assert(sizeof(ltdc_l1ckcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1PFCR register
 *
 * LTDC layer 1 pixel format configuration register
 *
 *  @note offset: 0x94UL
 *        width:  32 bits
 */
#define LTDC_L1PFCR_REG  0x94UL

/**
 * @brief LTDC L1PFCR PF field
 *
 * pixel format These bits configure the pixel format
 *
 * @note offset: 0x0UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L1PFCR_PF_SHIFT 0x0UL
#define LTDC_L1PFCR_PF_MASK (((1ULL << 3) - 1) << LTDC_L1PFCR_PF_SHIFT)


struct ltdc_l1pfcr {
    uint32_t pf:3;
    };

typedef struct ltdc_l1pfcr ltdc_l1pfcr_t;
static_assert(sizeof(ltdc_l1pfcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CACR register
 *
 * LTDC layer 1 constant alpha configuration register
 *
 *  @note offset: 0x98UL
 *        width:  32 bits
 */
#define LTDC_L1CACR_REG  0x98UL

/**
 * @brief LTDC L1CACR CONSTA field
 *
 * constant alpha These bits configure the constant alpha used for blending. The constant alpha is divided by 255 by hardware. Example: if the programmed constant alpha is 0xFF, the constant alpha value is 255 / 255 = 1.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1CACR_CONSTA_SHIFT 0x0UL
#define LTDC_L1CACR_CONSTA_MASK (((1ULL << 8) - 1) << LTDC_L1CACR_CONSTA_SHIFT)


struct ltdc_l1cacr {
    uint32_t consta:8;
    };

typedef struct ltdc_l1cacr ltdc_l1cacr_t;
static_assert(sizeof(ltdc_l1cacr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1DCCR register
 *
 * LTDC layer 1 default color configuration register
 *
 *  @note offset: 0x9cUL
 *        width:  32 bits
 */
#define LTDC_L1DCCR_REG  0x9cUL

/**
 * @brief LTDC L1DCCR DCBLUE field
 *
 * default color blue These bits configure the default blue value.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1DCCR_DCBLUE_SHIFT 0x0UL
#define LTDC_L1DCCR_DCBLUE_MASK (((1ULL << 8) - 1) << LTDC_L1DCCR_DCBLUE_SHIFT)
/**
 * @brief LTDC L1DCCR DCGREEN field
 *
 * default color green These bits configure the default green value.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1DCCR_DCGREEN_SHIFT 0x8UL
#define LTDC_L1DCCR_DCGREEN_MASK (((1ULL << 8) - 1) << LTDC_L1DCCR_DCGREEN_SHIFT)
/**
 * @brief LTDC L1DCCR DCRED field
 *
 * default color red These bits configure the default red value.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1DCCR_DCRED_SHIFT 0x10UL
#define LTDC_L1DCCR_DCRED_MASK (((1ULL << 8) - 1) << LTDC_L1DCCR_DCRED_SHIFT)
/**
 * @brief LTDC L1DCCR DCALPHA field
 *
 * default color alpha These bits configure the default alpha value.
 *
 * @note offset: 0x18UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L1DCCR_DCALPHA_SHIFT 0x18UL
#define LTDC_L1DCCR_DCALPHA_MASK (((1ULL << 8) - 1) << LTDC_L1DCCR_DCALPHA_SHIFT)


struct ltdc_l1dccr {
    uint32_t dcblue:8;
    uint32_t dcgreen:8;
    uint32_t dcred:8;
    uint32_t dcalpha:8;
    };

typedef struct ltdc_l1dccr ltdc_l1dccr_t;
static_assert(sizeof(ltdc_l1dccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1BFCR register
 *
 * LTDC layer 1 blending factors configuration register
 *
 *  @note offset: 0xa0UL
 *        width:  32 bits
 */
#define LTDC_L1BFCR_REG  0xa0UL

/**
 * @brief LTDC L1BFCR BF2 field
 *
 * blending factor 2 These bits select the blending factor F2
 *
 * @note offset: 0x0UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L1BFCR_BF2_SHIFT 0x0UL
#define LTDC_L1BFCR_BF2_MASK (((1ULL << 3) - 1) << LTDC_L1BFCR_BF2_SHIFT)
/**
 * @brief LTDC L1BFCR BF1 field
 *
 * blending factor 1 These bits select the blending factor F1.
 *
 * @note offset: 0x8UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L1BFCR_BF1_SHIFT 0x8UL
#define LTDC_L1BFCR_BF1_MASK (((1ULL << 3) - 1) << LTDC_L1BFCR_BF1_SHIFT)


struct ltdc_l1bfcr {
    uint32_t bf2:3;
    uint32_t reserved0:5;
    uint32_t bf1:3;
    };

typedef struct ltdc_l1bfcr ltdc_l1bfcr_t;
static_assert(sizeof(ltdc_l1bfcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CFBAR register
 *
 * LTDC layer 1 color frame buffer address register
 *
 *  @note offset: 0xacUL
 *        width:  32 bits
 */
#define LTDC_L1CFBAR_REG  0xacUL

/**
 * @brief LTDC L1CFBAR CFBADD field
 *
 * color frame buffer start address These bits define the color frame buffer start address.
 *
 * @note offset: 0x0UL
 *       width:  32
 *       access: read-write
 */
#define LTDC_L1CFBAR_CFBADD_SHIFT 0x0UL
#define LTDC_L1CFBAR_CFBADD_MASK (((1ULL << 32) - 1) << LTDC_L1CFBAR_CFBADD_SHIFT)


struct ltdc_l1cfbar {
    uint32_t cfbadd:32;
    };

typedef struct ltdc_l1cfbar ltdc_l1cfbar_t;
static_assert(sizeof(ltdc_l1cfbar_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CFBLR register
 *
 * LTDC layer 1 color frame buffer length register
 *
 *  @note offset: 0xb0UL
 *        width:  32 bits
 */
#define LTDC_L1CFBLR_REG  0xb0UL

/**
 * @brief LTDC L1CFBLR CFBLL field
 *
 * color frame buffer line length These bits define the length of one line of pixels in bytes + 3. The line length is computed as follows: active high width * number of bytes per pixel + 3.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-write
 */
#define LTDC_L1CFBLR_CFBLL_SHIFT 0x0UL
#define LTDC_L1CFBLR_CFBLL_MASK (((1ULL << 13) - 1) << LTDC_L1CFBLR_CFBLL_SHIFT)
/**
 * @brief LTDC L1CFBLR CFBP field
 *
 * color frame buffer pitch in bytes These bits define the pitch that is the increment from the start of one line of pixels to the start of the next line in bytes.
 *
 * @note offset: 0x10UL
 *       width:  13
 *       access: read-write
 */
#define LTDC_L1CFBLR_CFBP_SHIFT 0x10UL
#define LTDC_L1CFBLR_CFBP_MASK (((1ULL << 13) - 1) << LTDC_L1CFBLR_CFBP_SHIFT)


struct ltdc_l1cfblr {
    uint32_t cfbll:13;
    uint32_t reserved0:3;
    uint32_t cfbp:13;
    };

typedef struct ltdc_l1cfblr ltdc_l1cfblr_t;
static_assert(sizeof(ltdc_l1cfblr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CFBLNR register
 *
 * LTDC layer 1 color frame buffer line number register
 *
 *  @note offset: 0xb4UL
 *        width:  32 bits
 */
#define LTDC_L1CFBLNR_REG  0xb4UL

/**
 * @brief LTDC L1CFBLNR CFBLNBR field
 *
 * frame buffer line number These bits define the number of lines in the frame buffer that corresponds to the active high width.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L1CFBLNR_CFBLNBR_SHIFT 0x0UL
#define LTDC_L1CFBLNR_CFBLNBR_MASK (((1ULL << 11) - 1) << LTDC_L1CFBLNR_CFBLNBR_SHIFT)


struct ltdc_l1cfblnr {
    uint32_t cfblnbr:11;
    };

typedef struct ltdc_l1cfblnr ltdc_l1cfblnr_t;
static_assert(sizeof(ltdc_l1cfblnr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L1CLUTWR register
 *
 * LTDC layer 1 CLUT write register
 *
 *  @note offset: 0xc4UL
 *        width:  32 bits
 */
#define LTDC_L1CLUTWR_REG  0xc4UL

/**
 * @brief LTDC L1CLUTWR BLUE field
 *
 * blue value These bits configure the blue value.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L1CLUTWR_BLUE_SHIFT 0x0UL
#define LTDC_L1CLUTWR_BLUE_MASK (((1ULL << 8) - 1) << LTDC_L1CLUTWR_BLUE_SHIFT)
/**
 * @brief LTDC L1CLUTWR GREEN field
 *
 * green value These bits configure the green value.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L1CLUTWR_GREEN_SHIFT 0x8UL
#define LTDC_L1CLUTWR_GREEN_MASK (((1ULL << 8) - 1) << LTDC_L1CLUTWR_GREEN_SHIFT)
/**
 * @brief LTDC L1CLUTWR RED field
 *
 * red value These bits configure the red value.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L1CLUTWR_RED_SHIFT 0x10UL
#define LTDC_L1CLUTWR_RED_MASK (((1ULL << 8) - 1) << LTDC_L1CLUTWR_RED_SHIFT)
/**
 * @brief LTDC L1CLUTWR CLUTADD field
 *
 * CLUT address These bits configure the CLUT address (color position within the CLUT) of each RGB value.
 *
 * @note offset: 0x18UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L1CLUTWR_CLUTADD_SHIFT 0x18UL
#define LTDC_L1CLUTWR_CLUTADD_MASK (((1ULL << 8) - 1) << LTDC_L1CLUTWR_CLUTADD_SHIFT)


struct ltdc_l1clutwr {
    uint32_t blue:8;
    uint32_t green:8;
    uint32_t red:8;
    uint32_t clutadd:8;
    };

typedef struct ltdc_l1clutwr ltdc_l1clutwr_t;
static_assert(sizeof(ltdc_l1clutwr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CR register
 *  @note offset: 0x104UL
 *        width:  32 bits
 */
#define LTDC_L2CR_REG  0x104UL

/**
 * @brief LTDC L2CR LEN field
 *
 * layer enable This bit is set and cleared by software.
 *
 * @note offset: 0x0UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L2CR_LEN (1UL << 0x0UL)
#define LTDC_L2CR_LEN_SHIFT 0x0UL
#define LTDC_L2CR_LEN_MASK (((1ULL << 1) - 1) << LTDC_L2CR_LEN_SHIFT)
/**
 * @brief LTDC L2CR COLKEN field
 *
 * color keying enable This bit is set and cleared by software.
 *
 * @note offset: 0x1UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L2CR_COLKEN (1UL << 0x1UL)
#define LTDC_L2CR_COLKEN_SHIFT 0x1UL
#define LTDC_L2CR_COLKEN_MASK (((1ULL << 1) - 1) << LTDC_L2CR_COLKEN_SHIFT)
/**
 * @brief LTDC L2CR CLUTEN field
 *
 * color look-up table enable This bit is set and cleared by software. The CLUT is only meaningful for L8, AL44 and AL88 pixel format. Refer to table (CLUT)
 *
 * @note offset: 0x4UL
 *       width:  1
 *       access: read-write
 */
#define LTDC_L2CR_CLUTEN (1UL << 0x4UL)
#define LTDC_L2CR_CLUTEN_SHIFT 0x4UL
#define LTDC_L2CR_CLUTEN_MASK (((1ULL << 1) - 1) << LTDC_L2CR_CLUTEN_SHIFT)


struct ltdc_l2cr {
    uint32_t len:1;
    uint32_t colken:1;
    uint32_t reserved0:2;
    uint32_t cluten:1;
    };

typedef struct ltdc_l2cr ltdc_l2cr_t;
static_assert(sizeof(ltdc_l2cr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2WHPCR register
 *
 * LTDC layer 2 window horizontal position configuration register
 *
 *  @note offset: 0x108UL
 *        width:  32 bits
 */
#define LTDC_L2WHPCR_REG  0x108UL

/**
 * @brief LTDC L2WHPCR WHSTPOS field
 *
 * window horizontal start position These bits configure the first visible pixel of a line of the layer window. WHSTPOS[11:0] must be ≤ AAW[11:0] bits (programmed in LTDC_AWCR register).
 *
 * @note offset: 0x0UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_L2WHPCR_WHSTPOS_SHIFT 0x0UL
#define LTDC_L2WHPCR_WHSTPOS_MASK (((1ULL << 12) - 1) << LTDC_L2WHPCR_WHSTPOS_SHIFT)
/**
 * @brief LTDC L2WHPCR WHSPPOS field
 *
 * window horizontal stop position These bits configure the last visible pixel of a line of the layer window. WHSPPOS[11:0] must be ≥ AHBP[11:0] bits + 1 (programmed in LTDC_BPCR register).
 *
 * @note offset: 0x10UL
 *       width:  12
 *       access: read-write
 */
#define LTDC_L2WHPCR_WHSPPOS_SHIFT 0x10UL
#define LTDC_L2WHPCR_WHSPPOS_MASK (((1ULL << 12) - 1) << LTDC_L2WHPCR_WHSPPOS_SHIFT)


struct ltdc_l2whpcr {
    uint32_t whstpos:12;
    uint32_t reserved0:4;
    uint32_t whsppos:12;
    };

typedef struct ltdc_l2whpcr ltdc_l2whpcr_t;
static_assert(sizeof(ltdc_l2whpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2WVPCR register
 *
 * LTDC layer 2 window vertical position configuration register
 *
 *  @note offset: 0x10cUL
 *        width:  32 bits
 */
#define LTDC_L2WVPCR_REG  0x10cUL

/**
 * @brief LTDC L2WVPCR WVSTPOS field
 *
 * window vertical start position These bits configure the first visible line of the layer window. WVSTPOS[10:0] must be ≤ AAH[10:0] bits (programmed in LTDC_AWCR register).
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L2WVPCR_WVSTPOS_SHIFT 0x0UL
#define LTDC_L2WVPCR_WVSTPOS_MASK (((1ULL << 11) - 1) << LTDC_L2WVPCR_WVSTPOS_SHIFT)
/**
 * @brief LTDC L2WVPCR WVSPPOS field
 *
 * window vertical stop position These bits configure the last visible line of the layer window. WVSPPOS[10:0] must be ≥ AVBP[10:0] bits + 1 (programmed in LTDC_BPCR register).
 *
 * @note offset: 0x10UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L2WVPCR_WVSPPOS_SHIFT 0x10UL
#define LTDC_L2WVPCR_WVSPPOS_MASK (((1ULL << 11) - 1) << LTDC_L2WVPCR_WVSPPOS_SHIFT)


struct ltdc_l2wvpcr {
    uint32_t wvstpos:11;
    uint32_t reserved0:5;
    uint32_t wvsppos:11;
    };

typedef struct ltdc_l2wvpcr ltdc_l2wvpcr_t;
static_assert(sizeof(ltdc_l2wvpcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CKCR register
 *
 * LTDC layer 2 color keying configuration register
 *
 *  @note offset: 0x110UL
 *        width:  32 bits
 */
#define LTDC_L2CKCR_REG  0x110UL

/**
 * @brief LTDC L2CKCR CKBLUE field
 *
 * color key blue value
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2CKCR_CKBLUE_SHIFT 0x0UL
#define LTDC_L2CKCR_CKBLUE_MASK (((1ULL << 8) - 1) << LTDC_L2CKCR_CKBLUE_SHIFT)
/**
 * @brief LTDC L2CKCR CKGREEN field
 *
 * color key green value
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2CKCR_CKGREEN_SHIFT 0x8UL
#define LTDC_L2CKCR_CKGREEN_MASK (((1ULL << 8) - 1) << LTDC_L2CKCR_CKGREEN_SHIFT)
/**
 * @brief LTDC L2CKCR CKRED field
 *
 * color key red value
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2CKCR_CKRED_SHIFT 0x10UL
#define LTDC_L2CKCR_CKRED_MASK (((1ULL << 8) - 1) << LTDC_L2CKCR_CKRED_SHIFT)


struct ltdc_l2ckcr {
    uint32_t ckblue:8;
    uint32_t ckgreen:8;
    uint32_t ckred:8;
    };

typedef struct ltdc_l2ckcr ltdc_l2ckcr_t;
static_assert(sizeof(ltdc_l2ckcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2PFCR register
 *
 * LTDC layer 2 pixel format configuration register
 *
 *  @note offset: 0x114UL
 *        width:  32 bits
 */
#define LTDC_L2PFCR_REG  0x114UL

/**
 * @brief LTDC L2PFCR PF field
 *
 * pixel format These bits configure the pixel format
 *
 * @note offset: 0x0UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L2PFCR_PF_SHIFT 0x0UL
#define LTDC_L2PFCR_PF_MASK (((1ULL << 3) - 1) << LTDC_L2PFCR_PF_SHIFT)


struct ltdc_l2pfcr {
    uint32_t pf:3;
    };

typedef struct ltdc_l2pfcr ltdc_l2pfcr_t;
static_assert(sizeof(ltdc_l2pfcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CACR register
 *
 * LTDC layer 2 constant alpha configuration register
 *
 *  @note offset: 0x118UL
 *        width:  32 bits
 */
#define LTDC_L2CACR_REG  0x118UL

/**
 * @brief LTDC L2CACR CONSTA field
 *
 * constant alpha These bits configure the constant alpha used for blending. The constant alpha is divided by 255 by hardware. Example: if the programmed constant alpha is 0xFF, the constant alpha value is 255 / 255 = 1.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2CACR_CONSTA_SHIFT 0x0UL
#define LTDC_L2CACR_CONSTA_MASK (((1ULL << 8) - 1) << LTDC_L2CACR_CONSTA_SHIFT)


struct ltdc_l2cacr {
    uint32_t consta:8;
    };

typedef struct ltdc_l2cacr ltdc_l2cacr_t;
static_assert(sizeof(ltdc_l2cacr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2DCCR register
 *
 * LTDC layer 2 default color configuration register
 *
 *  @note offset: 0x11cUL
 *        width:  32 bits
 */
#define LTDC_L2DCCR_REG  0x11cUL

/**
 * @brief LTDC L2DCCR DCBLUE field
 *
 * default color blue These bits configure the default blue value.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2DCCR_DCBLUE_SHIFT 0x0UL
#define LTDC_L2DCCR_DCBLUE_MASK (((1ULL << 8) - 1) << LTDC_L2DCCR_DCBLUE_SHIFT)
/**
 * @brief LTDC L2DCCR DCGREEN field
 *
 * default color green These bits configure the default green value.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2DCCR_DCGREEN_SHIFT 0x8UL
#define LTDC_L2DCCR_DCGREEN_MASK (((1ULL << 8) - 1) << LTDC_L2DCCR_DCGREEN_SHIFT)
/**
 * @brief LTDC L2DCCR DCRED field
 *
 * default color red These bits configure the default red value.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2DCCR_DCRED_SHIFT 0x10UL
#define LTDC_L2DCCR_DCRED_MASK (((1ULL << 8) - 1) << LTDC_L2DCCR_DCRED_SHIFT)
/**
 * @brief LTDC L2DCCR DCALPHA field
 *
 * default color alpha These bits configure the default alpha value.
 *
 * @note offset: 0x18UL
 *       width:  8
 *       access: read-write
 */
#define LTDC_L2DCCR_DCALPHA_SHIFT 0x18UL
#define LTDC_L2DCCR_DCALPHA_MASK (((1ULL << 8) - 1) << LTDC_L2DCCR_DCALPHA_SHIFT)


struct ltdc_l2dccr {
    uint32_t dcblue:8;
    uint32_t dcgreen:8;
    uint32_t dcred:8;
    uint32_t dcalpha:8;
    };

typedef struct ltdc_l2dccr ltdc_l2dccr_t;
static_assert(sizeof(ltdc_l2dccr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2BFCR register
 *
 * LTDC layer 2 blending factors configuration register
 *
 *  @note offset: 0x120UL
 *        width:  32 bits
 */
#define LTDC_L2BFCR_REG  0x120UL

/**
 * @brief LTDC L2BFCR BF2 field
 *
 * blending factor 2 These bits select the blending factor F2
 *
 * @note offset: 0x0UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L2BFCR_BF2_SHIFT 0x0UL
#define LTDC_L2BFCR_BF2_MASK (((1ULL << 3) - 1) << LTDC_L2BFCR_BF2_SHIFT)
/**
 * @brief LTDC L2BFCR BF1 field
 *
 * blending factor 1 These bits select the blending factor F1.
 *
 * @note offset: 0x8UL
 *       width:  3
 *       access: read-write
 */
#define LTDC_L2BFCR_BF1_SHIFT 0x8UL
#define LTDC_L2BFCR_BF1_MASK (((1ULL << 3) - 1) << LTDC_L2BFCR_BF1_SHIFT)


struct ltdc_l2bfcr {
    uint32_t bf2:3;
    uint32_t reserved0:5;
    uint32_t bf1:3;
    };

typedef struct ltdc_l2bfcr ltdc_l2bfcr_t;
static_assert(sizeof(ltdc_l2bfcr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CFBAR register
 *
 * LTDC layer 2 color frame buffer address register
 *
 *  @note offset: 0x12cUL
 *        width:  32 bits
 */
#define LTDC_L2CFBAR_REG  0x12cUL

/**
 * @brief LTDC L2CFBAR CFBADD field
 *
 * color frame buffer start address These bits define the color frame buffer start address.
 *
 * @note offset: 0x0UL
 *       width:  32
 *       access: read-write
 */
#define LTDC_L2CFBAR_CFBADD_SHIFT 0x0UL
#define LTDC_L2CFBAR_CFBADD_MASK (((1ULL << 32) - 1) << LTDC_L2CFBAR_CFBADD_SHIFT)


struct ltdc_l2cfbar {
    uint32_t cfbadd:32;
    };

typedef struct ltdc_l2cfbar ltdc_l2cfbar_t;
static_assert(sizeof(ltdc_l2cfbar_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CFBLR register
 *
 * LTDC layer 2 color frame buffer length register
 *
 *  @note offset: 0x130UL
 *        width:  32 bits
 */
#define LTDC_L2CFBLR_REG  0x130UL

/**
 * @brief LTDC L2CFBLR CFBLL field
 *
 * color frame buffer line length These bits define the length of one line of pixels in bytes + 3. The line length is computed as follows: active high width * number of bytes per pixel + 3.
 *
 * @note offset: 0x0UL
 *       width:  13
 *       access: read-write
 */
#define LTDC_L2CFBLR_CFBLL_SHIFT 0x0UL
#define LTDC_L2CFBLR_CFBLL_MASK (((1ULL << 13) - 1) << LTDC_L2CFBLR_CFBLL_SHIFT)
/**
 * @brief LTDC L2CFBLR CFBP field
 *
 * color frame buffer pitch in bytes These bits define the pitch that is the increment from the start of one line of pixels to the start of the next line in bytes.
 *
 * @note offset: 0x10UL
 *       width:  13
 *       access: read-write
 */
#define LTDC_L2CFBLR_CFBP_SHIFT 0x10UL
#define LTDC_L2CFBLR_CFBP_MASK (((1ULL << 13) - 1) << LTDC_L2CFBLR_CFBP_SHIFT)


struct ltdc_l2cfblr {
    uint32_t cfbll:13;
    uint32_t reserved0:3;
    uint32_t cfbp:13;
    };

typedef struct ltdc_l2cfblr ltdc_l2cfblr_t;
static_assert(sizeof(ltdc_l2cfblr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CFBLNR register
 *
 * LTDC layer 2 color frame buffer line number register
 *
 *  @note offset: 0x134UL
 *        width:  32 bits
 */
#define LTDC_L2CFBLNR_REG  0x134UL

/**
 * @brief LTDC L2CFBLNR CFBLNBR field
 *
 * frame buffer line number These bits define the number of lines in the frame buffer that corresponds to the active high width.
 *
 * @note offset: 0x0UL
 *       width:  11
 *       access: read-write
 */
#define LTDC_L2CFBLNR_CFBLNBR_SHIFT 0x0UL
#define LTDC_L2CFBLNR_CFBLNBR_MASK (((1ULL << 11) - 1) << LTDC_L2CFBLNR_CFBLNBR_SHIFT)


struct ltdc_l2cfblnr {
    uint32_t cfblnbr:11;
    };

typedef struct ltdc_l2cfblnr ltdc_l2cfblnr_t;
static_assert(sizeof(ltdc_l2cfblnr_t) == sizeof(uint32_t), "Invalid register description");

/**
 *  @brief LTDC L2CLUTWR register
 *
 * LTDC layer 2 CLUT write register
 *
 *  @note offset: 0x144UL
 *        width:  32 bits
 */
#define LTDC_L2CLUTWR_REG  0x144UL

/**
 * @brief LTDC L2CLUTWR BLUE field
 *
 * blue value These bits configure the blue value.
 *
 * @note offset: 0x0UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L2CLUTWR_BLUE_SHIFT 0x0UL
#define LTDC_L2CLUTWR_BLUE_MASK (((1ULL << 8) - 1) << LTDC_L2CLUTWR_BLUE_SHIFT)
/**
 * @brief LTDC L2CLUTWR GREEN field
 *
 * green value These bits configure the green value.
 *
 * @note offset: 0x8UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L2CLUTWR_GREEN_SHIFT 0x8UL
#define LTDC_L2CLUTWR_GREEN_MASK (((1ULL << 8) - 1) << LTDC_L2CLUTWR_GREEN_SHIFT)
/**
 * @brief LTDC L2CLUTWR RED field
 *
 * red value These bits configure the red value.
 *
 * @note offset: 0x10UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L2CLUTWR_RED_SHIFT 0x10UL
#define LTDC_L2CLUTWR_RED_MASK (((1ULL << 8) - 1) << LTDC_L2CLUTWR_RED_SHIFT)
/**
 * @brief LTDC L2CLUTWR CLUTADD field
 *
 * CLUT address These bits configure the CLUT address (color position within the CLUT) of each RGB value.
 *
 * @note offset: 0x18UL
 *       width:  8
 *       access: write-only
 */
#define LTDC_L2CLUTWR_CLUTADD_SHIFT 0x18UL
#define LTDC_L2CLUTWR_CLUTADD_MASK (((1ULL << 8) - 1) << LTDC_L2CLUTWR_CLUTADD_SHIFT)


struct ltdc_l2clutwr {
    uint32_t blue:8;
    uint32_t green:8;
    uint32_t red:8;
    uint32_t clutadd:8;
    };

typedef struct ltdc_l2clutwr ltdc_l2clutwr_t;
static_assert(sizeof(ltdc_l2clutwr_t) == sizeof(uint32_t), "Invalid register description");

/*@

    predicate ltdc_is_writable_register(ℤ r) = (
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x24 ||
        r == 0x2c ||
        r == 0x34 ||
        r == 0x40 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x90 ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xac ||
        r == 0xb0 ||
        r == 0xb4 ||
        r == 0x104 ||
        r == 0x108 ||
        r == 0x10c ||
        r == 0x110 ||
        r == 0x114 ||
        r == 0x118 ||
        r == 0x11c ||
        r == 0x120 ||
        r == 0x12c ||
        r == 0x130 ||
        r == 0x134 ||
        \false
    );

    predicate ltdc_is_readable_register(ℤ r) = (
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x24 ||
        r == 0x2c ||
        r == 0x34 ||
        r == 0x38 ||
        r == 0x40 ||
        r == 0x44 ||
        r == 0x48 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x90 ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xac ||
        r == 0xb0 ||
        r == 0xb4 ||
        r == 0x104 ||
        r == 0x108 ||
        r == 0x10c ||
        r == 0x110 ||
        r == 0x114 ||
        r == 0x118 ||
        r == 0x11c ||
        r == 0x120 ||
        r == 0x12c ||
        r == 0x130 ||
        r == 0x134 ||
        \false
    );

    predicate ltdc_register_exists(ℤ r) = (
        r == 0x8 ||
        r == 0xc ||
        r == 0x10 ||
        r == 0x14 ||
        r == 0x18 ||
        r == 0x24 ||
        r == 0x2c ||
        r == 0x34 ||
        r == 0x38 ||
        r == 0x3c ||
        r == 0x40 ||
        r == 0x44 ||
        r == 0x48 ||
        r == 0x84 ||
        r == 0x88 ||
        r == 0x8c ||
        r == 0x90 ||
        r == 0x94 ||
        r == 0x98 ||
        r == 0x9c ||
        r == 0xa0 ||
        r == 0xac ||
        r == 0xb0 ||
        r == 0xb4 ||
        r == 0xc4 ||
        r == 0x104 ||
        r == 0x108 ||
        r == 0x10c ||
        r == 0x110 ||
        r == 0x114 ||
        r == 0x118 ||
        r == 0x11c ||
        r == 0x120 ||
        r == 0x12c ||
        r == 0x130 ||
        r == 0x134 ||
        r == 0x144 ||
        \false
    );


*/

#endif /* __STM32U599_LTDC_DEFS_H */
