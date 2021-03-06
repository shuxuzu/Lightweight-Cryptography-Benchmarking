/*
 * Copyright (C) 2020 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LW_INTERNAL_TINYJAMBU_H
#define LW_INTERNAL_TINYJAMBU_H

#include <stdint.h>

/**
 * \file internal-tinyjambu.h
 * \brief Internal implementation of the TinyJAMBU permutation.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Size of the TinyJAMBU state in 32-bit words.
 */
#define TINY_JAMBU_STATE_SIZE 4

/**
 * \brief Converts a number of steps into a number of rounds, where each
 * round consists of 128 steps.
 *
 * \param steps The number of steps to perform; 384, 1024, 1152, or 1280.
 *
 * \return The number of rounds corresponding to \a steps.
 */
#define TINYJAMBU_ROUNDS(steps) ((steps) / 128)

/**
 * \brief Perform the TinyJAMBU-128 permutation.
 *
 * \param state TinyJAMBU-128 state to be permuted.
 * \param key Points to the 4 key words.
 * \param rounds The number of rounds to perform.
 */
void tiny_jambu_permutation_128
    (uint32_t state[TINY_JAMBU_STATE_SIZE], const uint32_t *key,
     unsigned rounds);

/**
 * \brief Perform the TinyJAMBU-192 permutation.
 *
 * \param state TinyJAMBU-192 state to be permuted.
 * \param key Points to the 6 key words.
 * \param rounds The number of rounds to perform.
 */
void tiny_jambu_permutation_192
    (uint32_t state[TINY_JAMBU_STATE_SIZE], const uint32_t *key,
     unsigned rounds);

/**
 * \brief Perform the TinyJAMBU-256 permutation.
 *
 * \param state TinyJAMBU-256 state to be permuted.
 * \param key Points to the 8 key words.
 * \param rounds The number of rounds to perform.
 */
void tiny_jambu_permutation_256
    (uint32_t state[TINY_JAMBU_STATE_SIZE], const uint32_t *key,
     unsigned rounds);

#ifdef __cplusplus
}
#endif

#endif
