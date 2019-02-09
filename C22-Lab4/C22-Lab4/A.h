#pragma once
#include <ostream>
using namespace std;


class A
{
public:
	int point;

	A(const int& other) :point(other) {};
	A(A&other) { point = other.point; };
	A(A&&other){ point = other.point; };
	A& operator=(A&other) { point = other.point; };
	A& operator=(A&&other) { point = other.point; };
	inline friend ostream& operator << (ostream& os,const A& other)
	{
		os << other.point;
		return os;
	}

	~A() {};
};
