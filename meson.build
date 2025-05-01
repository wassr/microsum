project('microsum', 'c',
		version: '0.0.0',
		license: 'MPL-2.0'
)

# Read configuration
config = configuration_data()

subdir('inc')

# Microsum library
libmicrosum = library(
	'microsum',
	sources: ['lib/core.c'],
	include_directories: include_dir,
	install: true
)

# CLI executable
cli = executable(
	'usum',
	sources: ['cli/main.c'],
	include_directories: include_dir,
	link_with: libmicrosum,
	install: true
)

# Install headers
#install_headers('inc/microsum/core.h', subdir: 'microsum')
#install_headers('inc/microsum/config.h', subdir: 'microsum')
