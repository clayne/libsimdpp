/*  Copyright (C) 2016  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_REDUCE_OR_H
#define LIBSIMDPP_SIMDPP_CORE_I_REDUCE_OR_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/i_reduce_or.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the bitwise OR of the elements in the vector

    @code
    r0 = a0 & a1 & a2 & ...
    @endcode
*/
template<unsigned N> SIMDPP_INL
int8_t reduce_or(const int8<N>& a)
{
    return detail::insn::i_reduce_or(uint8<N>(a));
}

template<unsigned N> SIMDPP_INL
uint8_t reduce_or(const uint8<N>& a)
{
    return detail::insn::i_reduce_or(a);
}

template<unsigned N> SIMDPP_INL
int16_t reduce_or(const int16<N>& a)
{
    return detail::insn::i_reduce_or(uint16<N>(a));
}

template<unsigned N> SIMDPP_INL
uint16_t reduce_or(const uint16<N>& a)
{
    return detail::insn::i_reduce_or(a);
}

template<unsigned N> SIMDPP_INL
int32_t reduce_or(const int32<N>& a)
{
    return detail::insn::i_reduce_or(uint32<N>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_or(const uint32<N>& a)
{
    return detail::insn::i_reduce_or(a);
}

template<unsigned N> SIMDPP_INL
int64_t reduce_or(const int64<N>& a)
{
    return detail::insn::i_reduce_or(uint64<N>(a));
}

template<unsigned N> SIMDPP_INL
uint64_t reduce_or(const uint64<N>& a)
{
    return detail::insn::i_reduce_or(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

