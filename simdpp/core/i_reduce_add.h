/*  Copyright (C) 2016  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_REDUCE_ADD_H
#define LIBSIMDPP_SIMDPP_CORE_I_REDUCE_ADD_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/i_reduce_add.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the sum of the elements in the vector. Intermediate and the
    final result has twice as many bits as the input element size in 8 and 16
    bit cases.

    @code
    r0 = a0 + a1 + a2 + ...
    @endcode
*/
template<unsigned N> SIMDPP_INL
int16_t reduce_add(const int8<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

template<unsigned N> SIMDPP_INL
uint16_t reduce_add(const uint8<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

template<unsigned N> SIMDPP_INL
int32_t reduce_add(const int16<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_add(const uint16<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

template<unsigned N> SIMDPP_INL
int32_t reduce_add(const int32<N>& a)
{
    return detail::insn::i_reduce_add(uint32<N>(a));
}

template<unsigned N> SIMDPP_INL
uint32_t reduce_add(const uint32<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

template<unsigned N> SIMDPP_INL
int64_t reduce_add(const int64<N>& a)
{
    return detail::insn::i_reduce_add(uint64<N>(a));
}

template<unsigned N> SIMDPP_INL
uint64_t reduce_add(const uint64<N>& a)
{
    return detail::insn::i_reduce_add(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

