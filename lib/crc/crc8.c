/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "microsum/crc/crc8.h"

static uint8_t reflect8(uint8_t b) {
    uint8_t r = 0;
    for (int i = 0; i < 8; ++i) {
        if (b & (1 << i)) { r |= (1 << (7 - i)); }
    }
    return r;
}

void msum_crc8_init(void*   state_ptr,
                    uint8_t poly,
                    uint8_t init,
                    uint8_t xor_out,
                    bool    ref_in,
                    bool    ref_out) {
    msum_crc8_state_t* state = (msum_crc8_state_t*)state_ptr;
    state->crc               = init;
    state->poly              = poly;
    state->xor_out           = xor_out;
    state->reflect_in        = ref_in;
    state->reflect_out       = ref_out;
}

void msum_crc8_update(void* state_ptr, size_t len, void* data_ptr) {
    msum_crc8_state_t* state = (msum_crc8_state_t*)state_ptr;
    uint8_t*           data  = (uint8_t*)data_ptr;

    for (size_t i = 0; i < len; ++i) {
        uint8_t byte = data[i];
        if (state->reflect_in) { byte = reflect8(byte); }
        state->crc ^= byte;
        for (int b = 0; b < 8; ++b) {
            if (state->crc & 0x80) {
                state->crc = (state->crc << 1) ^ state->poly;
            } else {
                state->crc <<= 1;
            }
        }
    }
}

void msum_crc8_finalize(void* state_ptr, void* output_ptr) {
    msum_crc8_state_t* state  = (msum_crc8_state_t*)state_ptr;
    uint8_t*           out    = (uint8_t*)output_ptr;
    uint8_t            result = state->crc;
    if (state->reflect_out) { result = reflect8(result); }
    *out = result ^ state->xor_out;
}

uint8_t msum_crc8_get(void* state_ptr) {
    uint8_t result;
    msum_crc8_finalize(state_ptr, &result);
    return result;
}
