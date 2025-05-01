/*
 * Copyright (c) 2025 Noel Atzwanger
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
 * the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

/*
 * The following sets the macros:
 *  - MSUM_PUBLIC
 *  - MSUM_PRIVATE
 *  - MSUM_STATIC
 * Setting MSUM_STATIC is straightforward as nearly all compilers respect the static keyword.
 * However, MSVC and CLANG/GCC have different ways to do this. If it cannot detect either of
 * those two, it will not make any annotations.
 *
 */

#define MSUM_STATIC static

#if defined _WIN32 || defined __CYGWIN__
  #ifdef MSUM_BUILDING
    #ifdef __GNUC__
      #define MSUM_PUBLIC __attribute__ ((dllexport))
    #else
      #define MSUM_PUBLIC __declspec(dllexport)
    #endif
  #else
    #ifdef __GNUC__
      #define MSUM_PUBLIC __attribute__ ((dllimport))
    #else
      #define MSUM_PUBLIC __declspec(dllimport)
    #endif
  #endif
  #define MSUM_PRIVATE
#else
  #if __GNUC__ >= 4
    #define MSUM_PUBLIC __attribute__ ((visibility ("default")))
    #define MSUM_PRIVATE __attribute__ ((visibility ("hidden")))
  #else
    #warning unknown compiler type, cannot set visablity
    #define MSUM_PUBLIC
    #define MSUM_PRIVATE
  #endif
#endif
