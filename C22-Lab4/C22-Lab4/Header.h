#pragma once
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <regex>
#include <cmath>
#include <ostream>
#include <istream>
#include "A.h"
#include "Book.h"
#include <set>
#include <tuple>

using namespace std;
template <typename T> void MyPrint(const T& first)
{
	cout << first;
}

template <typename T, typename... Types> void MyPrint(const T& first, const Types& ... rest)
{
	cout << first << " ";
	MyPrint(rest ...);
}

template <typename T> T _plus(T one, T two)
{
	return (one + two);
}


class product
{
public:
	double operator()(double one, double two)
	{
		return one * two;
	}
};

double _pow(double one, int two)
{
	return (two == 0) ? 1 : one * _pow(one, two-1);
}

double _div(double one, double two)
{
	double res = one / two;
	int res1 = res;
	double res2 = (res - res1)*two;
	return res2;
}

class bigger
{
public:
	double _max(double one, double two)
	{
		return (one > two) ? one : two;
	}
};

ostream& operator << (ostream& os, const set<Book>& other) 
{
	os << "\nБиблиотека:" << endl;
	int i = 1;
	for (auto x : other)
	{
		os << i++ <<".\n" << x << endl;
	}
	return os;
}