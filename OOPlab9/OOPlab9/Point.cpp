#include "Point.h"

bool Point::operator == (const Point& second) const
{
	return((one == second.one) && (two == second.two));
}


Point::~Point()
{
}
