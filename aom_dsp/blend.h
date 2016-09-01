/*
*  Copyright (c) 2016 The WebM project authors. All Rights Reserved.
*
*  Use of this source code is governed by a BSD-style license
*  that can be found in the LICENSE file in the root of the source
*  tree. An additional intellectual property rights grant can be found
*  in the file PATENTS.  All contributing project authors may
*  be found in the AUTHORS file in the root of the source tree.
*/

#ifndef AOM_DSP_BLEND_H_
#define AOM_DSP_BLEND_H_

#include "aom_ports/mem.h"

// Various blending functions and macros.
// See also the aom_blend_* functions in aom_dsp_rtcd.h

// Alpha blending with alpha values from the range [0, 64], where 64
// means use the first input and 0 means use the second input.
#define AOM_BLEND_A64_ROUND_BITS 6
#define AOM_BLEND_A64_MAX_ALPHA (1 << AOM_BLEND_A64_ROUND_BITS)  // 64

#define AOM_BLEND_A64(a, v0, v1)                                          \
  ROUND_POWER_OF_TWO((a) * (v0) + (AOM_BLEND_A64_MAX_ALPHA - (a)) * (v1), \
                     AOM_BLEND_A64_ROUND_BITS)

// Alpha blending with alpha values from the range [0, 256], where 256
// means use the first input and 0 means use the second input.
#define AOM_BLEND_A256_ROUND_BITS 8
#define AOM_BLEND_A256_MAX_ALPHA (1 << AOM_BLEND_A256_ROUND_BITS)  // 256

#define AOM_BLEND_A256(a, v0, v1)                                          \
  ROUND_POWER_OF_TWO((a) * (v0) + (AOM_BLEND_A256_MAX_ALPHA - (a)) * (v1), \
                     AOM_BLEND_A256_ROUND_BITS)

// Blending by averaging.
#define AOM_BLEND_AVG(v0, v1) ROUND_POWER_OF_TWO((v0) + (v1), 1)

#endif  // AOM_DSP_BLEND_H_