/*  Copyright (C) 2016  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_REDUCE_MAX_H
#define LIBSIMDPP_SIMDPP_CORE_I_REDUCE_MAX_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/i_reduce_max.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the maximum of the elements in the vector

    @code
    r0 = max(a0, a1, a2, ...)
    @endcode
*/
template<unsigned N> SIMDPP_INL
int8_t reduce_max(const int8<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
uint8_t reduce_max(const uint8<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
int16_t reduce_max(const int16<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
uint16_t reduce_max(const uint16<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
int32_t reduce_max(const int32<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_max(const uint32<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
int64_t reduce_max(const int64<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
uint64_t reduce_max(const uint64<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

