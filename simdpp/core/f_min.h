/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_F_MIN_H
#define LIBSIMDPP_SIMDPP_CORE_F_MIN_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/f_min.h>
#include <simdpp/core/detail/scalar_arg_impl.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

// note: SSE doesn't provide a way to propagate NaNs in min/max
/** Computes minimum of the values in two vectors. If at least one of the
    values is NaN, or both values are zeroes, it is unspecified which value
    will be returned.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)

    @endcode

    @par 256-bit version:
    @icost{SSE2-SSE4.1, NEON, ALTIVEC, 2}
*/
template<unsigned N> SIMDPP_INL
float32<N> min(const float32<N>& a, const float32<N>& b)
{
    return detail::insn::i_min(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(min, float32, float32)

/** Computes minima of the values in two vectors. If at least one of the values
    is NaN, or both values are zeroes, it is unspecified which value will be
    returned.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}

    @par 256-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-SSE4.1, 2}
*/
template<unsigned N> SIMDPP_INL
float64<N> min(const float64<N>& a, const float64<N>& b)
{
    return detail::insn::i_min(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(min, float64, float64)

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

