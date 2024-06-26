/*  Copyright (C) 2013-2017  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_SHUFFLE_BYTES16_H
#define LIBSIMDPP_SIMDPP_CORE_SHUFFLE_BYTES16_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/get_expr.h>
#include <simdpp/detail/insn/shuffle_bytes16.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

/** Selects bytes from two vectors according to a mask. Each byte within the
    mask defines which element to select:
     * Bits 7-5 must be zero or the behavior is undefined
     * Bit 4 defines which vector to select. 0 corresponds to @a a, 1 to @a b.
     * Bits 3-0 define the element within the selected vector.
*/
template<unsigned N, class V1, class V2> SIMDPP_INL
typename detail::get_expr_nomask<V1>::type
    shuffle_bytes16(const any_vec8<N,V1>& a, const any_vec8<N,V2>& b,
                    const uint8<N>& mask)
{
    typename detail::get_expr_nomask<V1>::type ra = a.wrapped(),
                                               rb = b.wrapped();
    return detail::insn::i_shuffle_bytes16(ra, rb, mask);
}

template<unsigned N, class V1, class V2> SIMDPP_INL
typename detail::get_expr_nomask<V1>::type
    shuffle_bytes16(const any_vec16<N,V1>& a, const any_vec16<N,V2>& b,
                    const uint16<N>& mask)
{
    typename detail::get_expr_nomask<V1>::type ra = a.wrapped(),
                                               rb = b.wrapped();
    return detail::insn::i_shuffle_bytes16(ra, rb, mask);
}

template<unsigned N, class V1, class V2> SIMDPP_INL
typename detail::get_expr_nomask<V1>::type
    shuffle_bytes16(const any_vec32<N,V1>& a, const any_vec32<N,V2>& b,
                    const uint32<N>& mask)
{
    typename detail::get_expr_nomask<V1>::type ra = a.wrapped(),
                                               rb = b.wrapped();
    return detail::insn::i_shuffle_bytes16(ra, rb, mask);
}

template<unsigned N, class V1, class V2> SIMDPP_INL
typename detail::get_expr_nomask<V1>::type
    shuffle_bytes16(const any_vec64<N,V1>& a, const any_vec64<N,V2>& b,
                    const uint64<N>& mask)
{
    typename detail::get_expr_nomask<V1>::type ra = a.wrapped(),
                                               rb = b.wrapped();
    return detail::insn::i_shuffle_bytes16(ra, rb, mask);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

