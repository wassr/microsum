config = configuration_data()

config.set('version', meson.project_version())
config.set('version-major', meson.project_version().split('.')[0])
config.set('version-minor', meson.project_version().split('.')[0])
src_root = meson.project_source_root()
commit = run_command(src_root / 'scripts' / 'commit.py', src_root, check: true).stdout()
config.set('git-commit', commit)
date = run_command(src_root / 'scripts' / 'date.py', check: true).stdout()
config.set('date', date)
cc = meson.get_compiler('c')
config.set('cc-id', cc.get_id())
config.set('cc-ver', cc.version())

conf_gen = configure_file(input: 'config.h.in', output: 'config.h', configuration: config)

lib_includes = [conf_gen, 'core.h', 'macros.h', 'query.h']

install_headers(lib_includes, subdir: 'microsum', preserve_path: true)