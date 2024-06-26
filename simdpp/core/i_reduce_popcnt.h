/*  Copyright (C) 2017  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_REDUCE_POPCNT_H
#define LIBSIMDPP_SIMDPP_CORE_I_REDUCE_POPCNT_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/i_reduce_popcnt.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the population count of all values in the vector.

    @code
    result = popcnt(a0) + popcnt(a1) + ...
    @endcode
*/
template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const int8<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N/4>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const uint8<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N/4>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const int16<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N/2>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const uint16<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N/2>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const int32<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const uint32<N>& a)
{
    return detail::insn::i_reduce_popcnt(a);
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const int64<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N*2>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_popcnt(const uint64<N>& a)
{
    return detail::insn::i_reduce_popcnt(uint32<N*2>(a));
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

