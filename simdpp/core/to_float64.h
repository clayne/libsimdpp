/*  Copyright (C) 2013-2017  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_TO_FLOAT64_H
#define LIBSIMDPP_SIMDPP_CORE_TO_FLOAT64_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/capabilities.h>
#include <simdpp/detail/insn/conv_any_to_float64.h>
#include <simdpp/detail/not_implemented.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

/** Converts elements within a vector to 64-bit floating-point values.

    SSE specific:

    If only inexact conversion can be performed, the current rounding mode is
    used.

    NEON specific:

    If only inexact conversion can be performed, round to nearest mode is used.

    @code
    r0 = (double) a0
    ...
    rN = (double) aN
    @endcode
*/
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const int8<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const uint8<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const int16<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const uint16<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const int32<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const uint32<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const int64<N>& a)
{
#if SIMDPP_HAS_INT64_TO_FLOAT64_CONVERSION
    return detail::insn::i_to_float64(a);
#else
    return SIMDPP_NOT_IMPLEMENTED_TEMPLATE0(a);
#endif
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const uint64<N>& a)
{
#if SIMDPP_HAS_UINT64_TO_FLOAT64_CONVERSION
    return detail::insn::i_to_float64(a);
#else
    return SIMDPP_NOT_IMPLEMENTED_TEMPLATE0(a);
#endif
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const float32<N>& a)
{
    return detail::insn::i_to_float64(a);
}
template<unsigned N> SIMDPP_INL
float64<N> to_float64(const float64<N>& a)
{
    return a;
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

