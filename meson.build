project(
    'microsum',
    'C',
    version: '0.0.0',
    license: 'MPL-2.0',
    meson_version: '>=1.1.0',
)

subdir('inc')
subdir('lib')
subdir('cli')

config = configuration_data()
config.set('prefix', get_option('prefix'))
config.set('libdir', get_option('libdir'))
config.set('includedir', get_option('includedir'))
config.set('version', meson.project_version())

configure_file(
    input: 'microsum.pc.in',
    output: 'microsum.pc',
    configuration: config,
    install: true,
    install_dir: get_option('prefix') / get_option('libdir') / 'pkgconfig'
)
