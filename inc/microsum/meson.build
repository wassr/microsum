config.set('MSUM_ENABLE_CORE', true)
conf_gen = configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: config
)

includes = [
    conf_gen,
    'core.h'
]
