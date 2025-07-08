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

#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>

typedef struct videomode {

    uint32_t pixelclock;    /**< pixel clock (kHz) */
    uint32_t hactive;       /**< horizontal pixel per lines */
    uint32_t hback_porch;   /**< horizontal backporch */
    uint32_t hfront_porch;  /**< horizontal frontporch */
    uint32_t hsync_len;     /**< horizontal sync pulse width */
    uint32_t vactive;       /**< vertical lines */
    uint32_t vback_porch;   /**< vertical backporch */
    uint32_t vfront_porch;  /**< vertical frontporch */
    uint32_t vsync_len;     /**< vertical sync pulse width */
} videomode_t;

/**
 * @brief LCD shadow load policy
 */
typedef enum lcd_shadow_load_mode {
    LCD_SHADOW_LOAD_IMMEDIATE, /**< reload shadowed register(s) immediatly */
    LCD_SHADOW_LOAD_VBLANK,    /**< reload shadowed register(s) at next vblank event */

    LCD_SHADOW_LOAD_LAST       /**< guard */
} lcd_shadow_load_mode_t;

int lcd_probe(const uint8_t lcd_id);

int lcd_map(const uint8_t id);
int lcd_unmap(const uint8_t id);

int lcd_enable(const uint8_t lcd_id);
int lcd_disable(const uint8_t lcd_id);

int lcd_plane_enable(const uint8_t lcd_id, const uint8_t plane_id);
int lcd_plane_disable(const uint8_t lcd_id, const uint8_t plane_id);
int lcd_plane_set_fbaddr(const uint8_t lcd_id, const uint8_t plane_id, uint32_t fbaddr);
int lcd_shadow_load(const uint8_t lcd_id, lcd_shadow_load_mode_t mode);



#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* __LCD_H */
