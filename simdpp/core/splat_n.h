/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_SPLAT_N_H
#define LIBSIMDPP_SIMDPP_CORE_SPLAT_N_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/splat_n.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

/** Broadcasts the specified 8-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    ...
    rN = a[s]
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSE3, 7}
    @icost{SSSE3-AVX, 1-2}
    @icost{AVX2, 2}

    @par 256-bit version:
    The lower and higher 128-bit halves are processed as if 128-bit instruction
    was applied to each of them separately.

    @icost{SSE2-SSE3, 14}
    @icost{SSSE3-AVX, 2-3}
    @icost{NEON, ALTIVEC, 2}
*/
template<unsigned s, unsigned N> SIMDPP_INL
int8<N> splat16(const int8<N>& a)
{
    static_assert(s < 16, "Access out of bounds");
    return detail::insn::i_splat16<s>(a);
    return { { a } };
}

template<unsigned s, unsigned N> SIMDPP_INL
uint8<N> splat16(const uint8<N>& a)
{
    static_assert(s < 16, "Access out of bounds");
    return detail::insn::i_splat16<s>(a);
}

/** Broadcasts the specified 16-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    ...
    r7 = a[s]
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSE3, 3}
    @icost{SSSE3-AVX, 1-2}
    @icost{AVX2, 2}

    @par 256-bit version:
    @icost{SSE2-SSE3, 6}
    @icost{SSSE3-AVX, 2-3}
    @icost{AVX2, NEON, ALTIVEC, 2}
*/
template<unsigned s, unsigned N> SIMDPP_INL
int16<N> splat8(const int16<N>& a)
{
    static_assert(s < 8, "Access out of bounds");
    return detail::insn::i_splat8<s>(a);
}

template<unsigned s, unsigned N> SIMDPP_INL
uint16<N> splat8(const uint16<N>& a)
{
    static_assert(s < 8, "Access out of bounds");
    return detail::insn::i_splat8<s>(a);
}

/** Broadcasts the specified 32-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    r2 = a[s]
    r3 = a[s]
    @endcode

    @par 256-bit version:
    @icost{NEON, ALTIVEC, 2}
*/
template<unsigned s, unsigned N> SIMDPP_INL
int32<N> splat4(const int32<N>& a)
{
    static_assert(s < 4, "Access out of bounds");
    return detail::insn::i_splat4<s>(a);
}

template<unsigned s, unsigned N> SIMDPP_INL
uint32<N> splat4(const uint32<N>& a)
{
    static_assert(s < 4, "Access out of bounds");
    return detail::insn::i_splat4<s>(a);
}

/** Broadcasts the specified 64-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    @endcode

    @par 128-bit version:
    @icost{ALTIVEC, 1-2}

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
    @icost{ALTIVEC, 2-3}
*/
template<unsigned s, unsigned N> SIMDPP_INL
int64<N> splat2(const int64<N>& a)
{
    static_assert(s < 2, "Access out of bounds");
    return detail::insn::i_splat2<s>(a);
}

template<unsigned s, unsigned N> SIMDPP_INL
uint64<N> splat2(const uint64<N>& a)
{
    static_assert(s < 2, "Access out of bounds");
    return detail::insn::i_splat2<s>(a);
}

/** Broadcasts the specified 32-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    r2 = a[s]
    r3 = a[s]
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned s, unsigned N> SIMDPP_INL
float32<N> splat4(const float32<N>& a)
{
    static_assert(s < 4, "Access out of bounds");
    return detail::insn::i_splat4<s>(a);
}

/** Broadcasts the specified 64-bit value to all elements within 128-bit lanes.

    @code
    r0 = a[s]
    r1 = a[s]
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}

    @par 256-bit version:
    @icost{SSE2-AVX, 2}
    @novec{NEON, ALTIVEC}
*/
template<unsigned s, unsigned N> SIMDPP_INL
float64<N> splat2(const float64<N>& a)
{
    static_assert(s < 2, "Access out of bounds");
    return detail::insn::i_splat2<s>(a);
}

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif

