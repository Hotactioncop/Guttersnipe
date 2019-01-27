#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
using namespace::std;


class Point
{
protected:
	int one;
	int two;
public:
	Point(int a = 0, int b = 0) :one(a), two(b) {};
	Point(const Point& other) { one = other.one; two = other.two; };
	Point& operator= (const Point&other) { one = other.one; two = other.two; return *this; };
	inline friend ostream& operator<< (ostream& os, const Point& other);
	bool operator == (const Point& second) const;
	friend bool operator < (const Point& first, const Point& second);
	~Point();
};

inline ostream& operator<< (ostream& os, const Point& other)
{
	os << other.one << " " << other.two << " ";
	return os;
}
