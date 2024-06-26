/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_TYPES_FLOAT64X8_H
#define LIBSIMDPP_SIMDPP_TYPES_FLOAT64X8_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/setup_arch.h>
#include <simdpp/types/fwd.h>
#include <simdpp/types/any.h>
#include <simdpp/types/int64x8.h>
#include <simdpp/core/cast.h>
#include <simdpp/detail/construct_eval.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

#if SIMDPP_USE_AVX512F

/// Class representing float64x8 vector
template<>
class float64<8> : public any_float64<8, float64<8>> {
public:
    static const unsigned type_tag = SIMDPP_TAG_FLOAT;
    using element_type = double;
    using base_vector_type = float64<8>;
    using expr_type = void;

#if SIMDPP_USE_AVX512F
    using native_type = __m512d;
#endif

    SIMDPP_INL float64<8>() = default;
    SIMDPP_INL float64<8>(const float64<8> &) = default;
    SIMDPP_INL float64<8> &operator=(const float64<8> &) = default;

    template<class V> SIMDPP_INL explicit float64<8>(const any_vec<64,V>& d)
    {
        *this = bit_cast<float64<8>>(d.wrapped());
    }
    template<class V> SIMDPP_INL float64<8>& operator=(const any_vec<64,V>& d)
    {
        *this = bit_cast<float64<8>>(d.wrapped()); return *this;
    }

    /// Construct from the underlying vector type
    SIMDPP_INL float64<8>(const native_type& d) : d_(d) {}
    SIMDPP_INL float64<8>& operator=(const native_type& d) { d_ = d; return *this; }

    /// Convert to the underlying vector type
#if !SIMDPP_DISABLE_DEPRECATED_CONVERSION_OPERATOR_TO_NATIVE_TYPES
    SIMDPP_INL operator native_type() const SIMDPP_IMPLICIT_CONVERSION_DEPRECATION_MSG
    { return d_; }
#endif
    SIMDPP_INL native_type native() const { return d_; }

    template<class E> SIMDPP_INL float64<8>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> SIMDPP_INL float64<8>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }

    /// Access base vectors
    SIMDPP_INL const float64<8>& vec(unsigned) const { return *this; }
    SIMDPP_INL float64<8>& vec(unsigned)       { return *this; }
    template<unsigned N> const float64<8>& vec() const { return *this; }
    template<unsigned N> float64<8>& vec() { return *this; }

private:
    native_type d_;
};


/// Class representing possibly optimized mask data for 8x 64-bit floating point
/// vector
template<>
class mask_float64<8> : public any_float64<8, mask_float64<8>> {
public:
    static const unsigned type_tag = SIMDPP_TAG_MASK_FLOAT;
    using base_vector_type = mask_float64<8>;
    using expr_type = void;

#if SIMDPP_USE_AVX512F
    using native_type = __mmask8;
#endif

    SIMDPP_INL mask_float64<8>() = default;
    SIMDPP_INL mask_float64<8>(const mask_float64<8> &) = default;
    SIMDPP_INL mask_float64<8> &operator=(const mask_float64<8> &) = default;

    SIMDPP_INL mask_float64<8>(const native_type& d) : d_(d) {}
    SIMDPP_INL mask_float64<8>& operator=(const native_type& d) { d_ = d; return *this; }

    SIMDPP_INL explicit mask_float64<8>(const mask_int64<8>& d)
    {
        *this = bit_cast<mask_float64<8>>(d);
    }
    SIMDPP_INL mask_float64<8>& operator=(const mask_int64<8>& d)
    {
        *this = bit_cast<mask_float64<8>>(d); return *this;
    }

    /// Convert to the underlying vector type
#if !SIMDPP_DISABLE_DEPRECATED_CONVERSION_OPERATOR_TO_NATIVE_TYPES
    SIMDPP_INL operator native_type() const SIMDPP_IMPLICIT_CONVERSION_DEPRECATION_MSG
    { return d_; }
#endif
    SIMDPP_INL native_type native() const { return d_; }

    /// Access the underlying type
    SIMDPP_INL float64<8> unmask() const
    {
    #if SIMDPP_USE_AVX512F
        // FIXME: remove cross-domain access
        __m512i bits = _mm512_maskz_set1_epi64(d_, 0xffffffffffffffff);
        return _mm512_castsi512_pd(bits);
    #endif
    }

    SIMDPP_INL const mask_float64<8>& vec(unsigned) const { return *this; }
    SIMDPP_INL mask_float64<8>& vec(unsigned)       { return *this; }
    template<unsigned N> const mask_float64<8>& vec() const { return *this; }
    template<unsigned N> mask_float64<8>& vec() { return *this; }

private:
    native_type d_;
};

#endif // SIMDPP_USE_AVX512F

} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif
