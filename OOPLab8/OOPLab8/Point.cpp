#include "Point.h"

bool Point::operator == (const Point& second) const
{
	return((one == second.one) && (two == second.two));
}

//bool Point::Neg(const Point& other) const
//{
//	return ((other.one < 0) || (other.two < 0));
//}


Point::~Point()
{
}
