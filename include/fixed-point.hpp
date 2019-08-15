// Fixed Point Type
//
// Author: Matthew Knight
// File Name: fixed-point.hpp
// Date: 2019-06-02

#pragma once

#include "gcem.hpp"

#include <iostream>

namespace {
	/**
	 * Rounding based on the number of fractional bits to truncate
	 */
	template <typename T, auto removeBits>
	constexpr auto round(T val) {
		if constexpr (removeBits > 0) {
			
		}

		return val;
	}
}

template <typename T, auto fractionalBits,
          typename = std::enable_if_t<std::is_integral_v<T>>>
struct FixedPoint {
    using Type = T;

	static constexpr auto decimal = fractionalBits;
    static constexpr auto epsilon = 1.0 / gcem::pow(2, decimal);

    T value;

    constexpr FixedPoint() = default;

    // floating point constructor
    template <
        typename FloatingPointType,
        typename = std::enable_if<std::is_floating_point_v<FloatingPointType>>>
    constexpr FixedPoint(FloatingPointType fp)
        : value(gcem::round(fp / epsilon)) {}

    // convert to floating point
    template <
        typename FloatingPointType,
        typename = std::enable_if<std::is_floating_point_v<FloatingPointType>>>
	constexpr operator FloatingPointType() const {
        return epsilon * value;
    }

    // arithmetic operators
    template <typename FixedPointType>
    constexpr decltype(auto) operator+(FixedPointType &other) const {
        static_assert(std::is_same_v<Type, typename FixedPointType::Type>);
        constexpr auto dec = gcem::min(decimal, FixedPointType::decimal);

		// rounding for mismatched 
		if constexpr (dec > 0) {

		}
		
		FixedPoint<T, dec> tmp{};
		tmp.value = (value >> (decimal - dec)) + (other.value >> (FixedPointType::decimal - dec));

        return tmp;
    }

    template <typename FixedPointType>
    constexpr decltype(auto) operator-(FixedPointType &other) const {
        static_assert(std::is_same_v<Type, typename FixedPointType::Type>);
        constexpr auto dec = gcem::min(decimal, FixedPointType::decimal);
		
		FixedPoint<T, dec> tmp{};
		tmp.value = (value >> (decimal - dec)) - (other.value >> (FixedPointType::decimal - dec));

        return tmp;
    }

    // TODO: rest of arithmetic operators, logical operators, bitwise operators
};
