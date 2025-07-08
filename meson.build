# SPDX-FileCopyrightText: 2024 Ledger SAS
# SPDX-License-Identifier: Apache-2.0

project('stm32-ltdc', 'c',
    meson_version: '>=1.3.0',
    version: run_command('dunamai', 'from', 'git', '--style', 'semver', '--dirty', check: true).stdout().strip(),
    default_options: [
        'c_std=gnu11',
        'warning_level=3', 'optimization=s',
        'default_library=static', 'b_staticpic=false',
        'licensedir=share/info/libsynospys-mipi',
        'pkgconfig.relocatable=true',
        'config=configs/defconfig',
        'dts=dts/default.dts',
        'dts-include-dirs=dts',
])

pkg = import('pkgconfig')
ssmod = import('sourceset')

stm32_ltdc_deps = []
stm32_ltdc_source_set = ssmod.source_set()
stm32_ltdc_inc = []
stm32_ltdc_compile_args = []

kconfig_file = meson.current_source_dir() / 'Kconfig'
kconfig_proj = subproject('kconfig', default_options: ['kconfig=@0@'.format(kconfig_file)])
kconfig_h = kconfig_proj.get_variable('kconfig_h')
kconfig_data = kconfig_proj.get_variable('kconfig_data')

devicetree_proj = subproject('devicetree')
dts = devicetree_proj.get_variable('devicetree_dtsd')
dts2src = devicetree_proj.get_variable('dts2src')
devicetree_dep = devicetree_proj.get_variable('devicetree_dep')

dtsgen = generator(dts2src,
    arguments: ['-d', dts.full_path() , '-t', '@INPUT@', '@OUTPUT@' ],
    depends: [ dts ],
    output: '@BASENAME@',
)

libshield_dep = dependency('shield')
stm32_ltdc_deps += [ libshield_dep ]

subdir('include')
subdir('src')

libstm32_ltdc_dep = declare_dependency(
    include_directories: stm32_ltdc_inc,
    link_with: stm32_ltdc_lib,
    dependencies: stm32_ltdc_deps,
    compile_args: stm32_ltdc_compile_args,
)

# TODO doc and test
