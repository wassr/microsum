/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "microsum/config.h"
#include "microsum/macros.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t crc;
    uint8_t poly;
    uint8_t xor_out;
    bool    reflect_in;
    bool    reflect_out;
} msum_crc8_state_t;

/**
 * @brief generic implementation of the CRC8 family or CRCs
 *
 * @param state     state object
 * @param poly      polynomial
 * @param init      the initial value of the sum
 * @param xor_out   pattern to xor bevor output
 * @param ref_in    reflect input
 * @param ref_out   reflect output
 */
MSUM_PUBLIC void    msum_crc8_init(void*   state,
                                   uint8_t poly,
                                   uint8_t init,
                                   uint8_t xor_out,
                                   bool    ref_in,
                                   bool    ref_out);
MSUM_PUBLIC void    msum_crc8_update(void* state, size_t len, void* data);
MSUM_PUBLIC void    msum_crc8_finalize(void* state, void* output);
MSUM_PUBLIC uint8_t msum_crc8_return(void* state);

MSUM_PUBLIC uint8_t msum_crc8_atm(uint8_t state, size_t len, void* data);
MSUM_PUBLIC uint8_t msum_crc8_maxim(uint8_t state, size_t len, void* data);
MSUM_PUBLIC uint8_t msum_crc8_autosar(uint8_t state, size_t len, void* data);
MSUM_PUBLIC uint8_t msum_crc8_darc(uint8_t state, size_t len, void* data);

