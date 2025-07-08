# SPDX-FileCopyrightText: 2024 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

stm32_ltdc_source_set.add(files(
    'stm32_ltdc.c',
))

stm32_ltdc_dt_c_in = files(['stm32_ltdc_dt.c.in'])
stm32_ltdc_dt_c = dtsgen.process(
    stm32_ltdc_dt_c_in,
    env: [ 'CONFIG_TASK_LABEL='+kconfig_data.get('CONFIG_TASK_LABEL', '0') ],
)
stm32_ltdc_source_set.add(stm32_ltdc_dt_c)

stm32_ltdc_sources = stm32_ltdc_source_set.apply(kconfig_data, strict: false)

stm32_ltdc_lib = static_library(
    meson.project_name(),
    sources : [ stm32_ltdc_sources.sources() ],
    c_args : [ stm32_ltdc_compile_args ],
    include_directories: [ stm32_ltdc_inc ],
    dependencies: [ stm32_ltdc_deps ],
    install: true,
)
