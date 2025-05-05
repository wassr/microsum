cli_srcs = ['main.c']

if get_option('build-cli')
    cli = executable(
        'usum',
        sources: cli_srcs,
        dependencies: cli_dep,
        install: true,
    )
endif