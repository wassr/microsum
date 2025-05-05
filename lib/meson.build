lib_srcs = ['core.c']
libs = []

if get_option('build-static')
    lib_static = static_library(
        'microsum',
        sources: lib_srcs,
        include_directories: lib_include_dir,
        install: true,
        pic: get_option('build-static-pic'),
    )
    libs += lib_static
    lib_static_dep = declare_dependency(include_directories: lib_include_dir, link_with: lib_static)
    if get_option('cli-link-type') == 'static'
        cli_dep = lib_static_dep
    endif
else
    message('Not building static libmircosum')
endif

if get_option('build-shared')
    lib_shared = shared_library(
        'microsum',
        sources: lib_srcs,
        include_directories: lib_include_dir,
        install: true,
    )
    libs += lib_shared
    lib_shared_dep = declare_dependency(include_directories: lib_include_dir, link_with: lib_shared)
    if get_option('cli-link-type') == 'shared'
        cli_dep = lib_shared_dep
    endif
else
    message('Not building shared libmicrosum')
endif

pkgconfig = import('pkgconfig')
pkgconfig.generate(
    libs[0],
    name: 'microsum',
    version: meson.project_version(),
    description: 'Portable, lightweight checksum and hash library in C',
)