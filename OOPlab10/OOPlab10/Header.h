#pragma once

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "Header.h"
#include "Point.h"
#include <ostream>
#include "Rect.h"

using namespace std;

#include <iostream>


bool operator < (const Point& first, const Point& second)
{
	return ((pow(first.one, 2) + pow(first.two, 2)) < (pow(second.one, 2) + pow(second.two, 2)));
}

bool operator < (const Rect& first, const Rect& second)
{
	return (((pow(first.x, 2) + pow(first.y, 2)) < (pow(second.x, 2) + pow(second.y, 2))) && ((pow(first.w, 2) + pow(first.z, 2)) < (pow(second.w, 2) + pow(second.z, 2))));
}

template <typename T> void Show_me(T& other)
{
	typename T::iterator it = other.begin();
	typename T::iterator ite = other.end();
	cout << endl;
	while (it != ite)
	{
		cout << *it << " ";
		++it;
	}
}
ostream& operator <<(ostream& os, vector<Point>& X)
{
	vector<Point>::iterator it = X.begin();
	vector<Point>::iterator ite = X.end();
	cout << endl;
	while (it != ite)
	{
		os << *it;
		++it;
	}
	return os;
}

template <typename T> void Print_it(const T& X)
{
	cout << X;
}

//void Change_it(const Point X)
//{
//	Point a(0, 0);
//	X = a;
//}

template <typename T> void Change_it(T& X)
{
	X = Point(0, 0);
}

bool Find_point(Point& X)
{
	return X < Point(5, 5);
}

void trans_it(string& X, string& Y)
{

}

string& to_lower(string& X)
{
	transform(X.begin(), X.end(), X.begin(), tolower);
	return X;
}

map<string, int>::value_type trans_map(string&X)
{
	return make_pair(X, 1);
}

template <typename T> void Show_map(T& other)
{
	typename T::iterator it = other.begin();
	typename T::iterator ite = other.end();
	cout << endl;
	while (it != ite)
	{
		cout << (*it).first << "\\" << (*it).second << " ";
		++it;
	}
}
