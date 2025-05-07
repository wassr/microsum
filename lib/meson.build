lib_srcs = ['core.c', 'query.c']

libs = []

if get_option('build-static')
    lib_static = static_library(
        'microsum',
        sources: lib_srcs,
        include_directories: lib_include_dir,
        install: true,
        c_args: '-DMSUM_STATIC',
        pic: get_option('build-static-pic'),
    )
    libs += lib_static
    lib_static_dep = declare_dependency(
        include_directories: lib_include_dir,
        link_with: lib_static,
        compile_args: '-DMSUM_STATIC',
    )
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