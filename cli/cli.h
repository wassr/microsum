/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    USUM_CONTINUE,
    USUM_ABORT,
    USUM_FINISHED,
} cli_mode_t;

typedef struct {
    // what to do
    bool help;
    bool usage;
    bool license;
    bool version;
    bool list;

    // verbosity
    bool verbose;
    bool quiet;

    // input
    uint32_t num_files;
    char** files;
    uint32_t num_dirs;
    char** dirs;

    // algorithms
    
} cli_args_t;


void help(void);
void usage(void);
cli_mode_t parse_args(uint32_t argc, char** argv, cli_args_t* args);

 