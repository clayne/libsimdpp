/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_CMP_GE_H
#define LIBSIMDPP_SIMDPP_CORE_CMP_GE_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/cmp_ge.h>
#include <simdpp/core/detail/scalar_arg_impl.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

/** Compares the values of two signed int16x8 vectors for greater-than

    @code
    r0 = (a0 >= b0) ? ~0x0 : 0x0
    ...
    rN = (aN >= bN) ? ~0x0 : 0x0
    @endcode
*/
template<unsigned N> SIMDPP_INL
mask_int8<N> cmp_ge(const int8<N>& a, const int8<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int8, int8)

template<unsigned N> SIMDPP_INL
mask_int8<N> cmp_ge(const uint8<N>& a, const uint8<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int8, uint8)

template<unsigned N> SIMDPP_INL
mask_int16<N> cmp_ge(const int16<N>& a, const int16<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int16, int16)

template<unsigned N> SIMDPP_INL
mask_int16<N> cmp_ge(const uint16<N>& a, const uint16<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int16, uint16)

template<unsigned N> SIMDPP_INL
mask_int32<N> cmp_ge(const int32<N>& a, const int32<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int32, int32)

template<unsigned N> SIMDPP_INL
mask_int32<N> cmp_ge(const uint32<N>& a, const uint32<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int32, uint32)

template<unsigned N> SIMDPP_INL
mask_int64<N> cmp_ge(const int64<N>& a, const int64<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int64, int64)

template<unsigned N> SIMDPP_INL
mask_int64<N> cmp_ge(const uint64<N>& a, const uint64<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}
SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_int64, uint64)

/** Compares the values of two float32x4 vectors for greater-than or equal

    @code
    r0 = (a0 >= b0) ? 0xffffffff : 0x0
    ...
    rN = (aN >= bN) ? 0xffffffff : 0x0
    @endcode

    @par 256-bit version:
    @icost{SSE2-SSE4.1, NEON, ALTIVEC, 2}
*/
template<unsigned N> SIMDPP_INL
mask_float32<N> cmp_ge(const float32<N>& a, const float32<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_float32, float32)

/** Compares the values of two float64x2 vectors for greater-than

    @code
    r0 = (a0 >= b0) ? 0xffffffffffffffff : 0x0
    ...
    rN = (aN >= bN) ? 0xffffffffffffffff : 0x0
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}

    @par 256-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-SSE4.1, 2}
*/
template<unsigned N> SIMDPP_INL
mask_float64<N> cmp_ge(const float64<N>& a, const float64<N>& b)
{
    return detail::insn::i_cmp_ge(a, b);
}

SIMDPP_SCALAR_ARG_IMPL_VEC(cmp_ge, mask_float64, float64)

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

