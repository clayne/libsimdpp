/*  Copyright (C) 2016  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_F_REDUCE_MIN_H
#define LIBSIMDPP_SIMDPP_CORE_F_REDUCE_MIN_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/f_reduce_min.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the minimum of the elements in the vector.

    @code
    r0 = min(a0, a1, a2, ...)
    @endcode
*/
template<unsigned N> SIMDPP_INL
float reduce_min(const float32<N>& a)
{
    return detail::insn::i_reduce_min(a);
}

template<unsigned N> SIMDPP_INL
double reduce_min(const float64<N>& a)
{
    return detail::insn::i_reduce_min(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

