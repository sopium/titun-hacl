/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __Hacl_HMAC_DRBG_H
#define __Hacl_HMAC_DRBG_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "evercrypt_targetconfig.h"
#include "libintvector.h"
#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include <string.h>
#include "kremlin/internal/target.h"


#include "Hacl_Spec.h"
#include "Hacl_HMAC.h"

/* SNIPPET_START: Hacl_HMAC_DRBG_supported_alg */

typedef Spec_Hash_Definitions_hash_alg Hacl_HMAC_DRBG_supported_alg;

/* SNIPPET_END: Hacl_HMAC_DRBG_supported_alg */

/* SNIPPET_START: Hacl_HMAC_DRBG_reseed_interval */

extern uint32_t Hacl_HMAC_DRBG_reseed_interval;

/* SNIPPET_END: Hacl_HMAC_DRBG_reseed_interval */

/* SNIPPET_START: Hacl_HMAC_DRBG_max_output_length */

extern uint32_t Hacl_HMAC_DRBG_max_output_length;

/* SNIPPET_END: Hacl_HMAC_DRBG_max_output_length */

/* SNIPPET_START: Hacl_HMAC_DRBG_max_length */

extern uint32_t Hacl_HMAC_DRBG_max_length;

/* SNIPPET_END: Hacl_HMAC_DRBG_max_length */

/* SNIPPET_START: Hacl_HMAC_DRBG_max_personalization_string_length */

extern uint32_t Hacl_HMAC_DRBG_max_personalization_string_length;

/* SNIPPET_END: Hacl_HMAC_DRBG_max_personalization_string_length */

/* SNIPPET_START: Hacl_HMAC_DRBG_max_additional_input_length */

extern uint32_t Hacl_HMAC_DRBG_max_additional_input_length;

/* SNIPPET_END: Hacl_HMAC_DRBG_max_additional_input_length */

/* SNIPPET_START: Hacl_HMAC_DRBG_min_length */

uint32_t Hacl_HMAC_DRBG_min_length(Spec_Hash_Definitions_hash_alg a);

/* SNIPPET_END: Hacl_HMAC_DRBG_min_length */

/* SNIPPET_START: Hacl_HMAC_DRBG_state */

typedef struct Hacl_HMAC_DRBG_state_s
{
  uint8_t *k;
  uint8_t *v;
  uint32_t *reseed_counter;
}
Hacl_HMAC_DRBG_state;

/* SNIPPET_END: Hacl_HMAC_DRBG_state */

/* SNIPPET_START: Hacl_HMAC_DRBG_uu___is_State */

bool
Hacl_HMAC_DRBG_uu___is_State(Spec_Hash_Definitions_hash_alg a, Hacl_HMAC_DRBG_state projectee);

/* SNIPPET_END: Hacl_HMAC_DRBG_uu___is_State */

/* SNIPPET_START: Hacl_HMAC_DRBG_create_in */

Hacl_HMAC_DRBG_state Hacl_HMAC_DRBG_create_in(Spec_Hash_Definitions_hash_alg a);

/* SNIPPET_END: Hacl_HMAC_DRBG_create_in */

/* SNIPPET_START: Hacl_HMAC_DRBG_instantiate */

void
Hacl_HMAC_DRBG_instantiate(
  Spec_Hash_Definitions_hash_alg a,
  Hacl_HMAC_DRBG_state st,
  uint32_t entropy_input_len,
  uint8_t *entropy_input,
  uint32_t nonce_len,
  uint8_t *nonce,
  uint32_t personalization_string_len,
  uint8_t *personalization_string
);

/* SNIPPET_END: Hacl_HMAC_DRBG_instantiate */

/* SNIPPET_START: Hacl_HMAC_DRBG_reseed */

void
Hacl_HMAC_DRBG_reseed(
  Spec_Hash_Definitions_hash_alg a,
  Hacl_HMAC_DRBG_state st,
  uint32_t entropy_input_len,
  uint8_t *entropy_input,
  uint32_t additional_input_input_len,
  uint8_t *additional_input_input
);

/* SNIPPET_END: Hacl_HMAC_DRBG_reseed */

/* SNIPPET_START: Hacl_HMAC_DRBG_generate */

bool
Hacl_HMAC_DRBG_generate(
  Spec_Hash_Definitions_hash_alg a,
  uint8_t *output,
  Hacl_HMAC_DRBG_state st,
  uint32_t n,
  uint32_t additional_input_len,
  uint8_t *additional_input
);

/* SNIPPET_END: Hacl_HMAC_DRBG_generate */

#if defined(__cplusplus)
}
#endif

#define __Hacl_HMAC_DRBG_H_DEFINED
#endif
