/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <microsum/config.h>
#include <microsum/core.h>

const char* msum_version(void) {
    return MSUM_VER_STR;
}

const int msum_version_minor(void) {
    return MSUM_VER_MAJOR;
}

const int msum_version_major(void) {
    return MSUM_VER_MINOR;
}

const char* msum_info(void) {
    return MSUM_INFO;
}
