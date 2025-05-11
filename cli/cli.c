/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "cli.h"

static char* usage_str = \
"usage: usum [-h,--help] [OPTIONS] [-a,--algo ALGO ...] [--] FILES..."
;


void usage(void) {
    printf(usage_str);
}

void help(void) {

}

cli_mode_t parse_args(uint32_t argc, char** argv, cli_args_t* args) {
    return USUM_FINISHED;
}