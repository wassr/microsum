/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <stdio.h>
#include <stdlib.h>

#include <microsum/core.h>

int
main(int argc, char* argv[])
{
    printf("Hello, World! (v%s)\n", msum_version());
    return EXIT_SUCCESS;
}
