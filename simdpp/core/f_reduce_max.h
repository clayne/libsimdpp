/*  Copyright (C) 2016  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_F_REDUCE_MAX_H
#define LIBSIMDPP_SIMDPP_CORE_F_REDUCE_MAX_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/f_reduce_max.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {


/** Computes the maximum of the elements in the vector.

    @code
    r0 = max(a0, a1, a2, ...)
    @endcode
*/
template<unsigned N> SIMDPP_INL
float reduce_max(const float32<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

template<unsigned N> SIMDPP_INL
double reduce_max(const float64<N>& a)
{
    return detail::insn::i_reduce_max(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

