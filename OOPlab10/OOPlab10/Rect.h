#pragma once
#include <ostream>
using namespace std;

class Rect
{
public:
	int x, y, w, z;
public:
	Rect(int a = 0, int b = 0, int c = 0, int d = 0) :x(a), y(b), w(c), z(d) {};
	Rect(const Rect& nRect) :x(nRect.x), y(nRect.y), w(nRect.w), z(nRect.z) {};
	Rect(const Rect&& nRect) :x(nRect.x), y(nRect.y), w(nRect.w), z(nRect.z) {};
	Rect& operator= (const Rect&other) { x = other.x; y = other.y; z = other.z; w = other.w; return *this; };
	inline friend ostream& operator<< (ostream& os, const Rect& other);
	bool operator == (const Rect& second) const { return((x == second.x) && (y == second.y) && (w == second.w) && (z == second.z)); };
	friend bool operator < (const Rect& first, const Rect& second);


	~Rect();
};

inline ostream& operator<< (ostream& os, const Rect& other)
{
	os << other.x << "x" << other.y << " " << other.w << "x" << other.z << " | ";
	return os;
}