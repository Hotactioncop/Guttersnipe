#pragma once

#include <iostream>

template <typename T> class Range
{
	T Min, Max;
public:
	constexpr Range(T low, T high) :Min(low), Max(high) {};
	constexpr T get_Min() const { return Min; };
	constexpr T get_Max() const {return Max;};
	constexpr bool check_range(T numb) const { return (numb >= Min && numb <= Max) ? true : false; };
	constexpr T put_in(T numb) const { return (numb < Min) ? Min : ((numb > Max) ? Max : numb); };
};