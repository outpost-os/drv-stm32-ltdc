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

#ifndef __STM32_LTDC_PRIV_H
#define __STM32_LTDC_PRIV_H

#include <stdatomic.h>

#include <handle.h>
#include <device.h>

__attribute__((always_inline))
static inline void iowrite32(size_t addr, uint32_t val)
{
    asm volatile(
        "str %1, %0" : : "Qo" (*(volatile uint32_t *)addr), "r" (val) : "memory"
    );
}

__attribute__((always_inline))
static inline uint32_t ioread32(size_t addr)
{
    uint32_t val;

    asm volatile(
        "ldr %0, %1" : "=r" (val) : "Qo" (*(volatile uint32_t *)addr) : "memory"
    );

    return val;
}

typedef struct stm32_ltdc_device {
    devinfo_t dev;
    /* Videomode might be a config property from chosen panel */
    videomode_t videomode;
    atomic_bool mapped;
    atomic_bool probed;
} stm32_ltdc_device_t;

__attribute__((always_inline))
static inline uint32_t stm32_ltdc_register_read(const devinfo_t *dev, size_t reg_offset)
{
    return ioread32(dev->baseaddr + reg_offset);
}

__attribute__((always_inline))
static inline void stm32_ltdc_register_write(const devinfo_t *dev, size_t reg_offset, uint32_t value)
{
    iowrite32(dev->baseaddr + reg_offset, value);
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x)   __builtin_expect(!!(x), 1)

stm32_ltdc_device_t *stm32_ltdc_get_device(const uint8_t id);


#endif /* __STM32_LTDC_PRIV_H */
