/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <microsum/core.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("%s\n", msum_info());
    return EXIT_SUCCESS;
}
