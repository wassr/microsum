/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <microsum/macros.h>

MSUM_PUBLIC const char* msum_version(void);
MSUM_PUBLIC const int   msum_version_minor(void);
MSUM_PUBLIC const int   msum_version_major(void);

MSUM_PUBLIC const char* msum_info(void);
