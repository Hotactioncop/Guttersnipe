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

using namespace std;

#include <iostream>
template <class T> const typename T::value_type& MyGet(const T& X)
{
	return X.top();
}

template < class T, class C> const T& MyGet(const queue<T,C>& X)
{
	return X.front();
}
template <class T> void Show_me(T X)
{
	cout << endl;
	while (X.size())
	{
		cout << MyGet(X) << ' ';
		X.pop();
	}
}




template <typename T> void Show_cont(const T&X)
{
	cout << endl;
	typename T::const_iterator it = X.begin();
	while (it != X.end())
	{
		cout << *it <<' ';
		++it;
	}
}


class cmp
{
public:
	bool operator()(const char*one, const char*two) const
	{
		return strcmp(one, two)>0;
	}
};

template <typename T> void Show_set(T&x)
{
	typename T::const_iterator it = x.begin();
	cout << endl;
	while (it != x.end())
	{
		cout << *it << " ";
		++it;
	}
}

bool operator < (const Point& first, const Point& second)
{
	return ((pow(first.one, 2) + pow(first.two, 2)) < (pow(second.one, 2) + pow(second.two, 2)));
}

template <typename T, typename string> void Show_map(const T&X, const string Y)
{
	cout << endl;
	typename T::const_iterator it = X.begin();
	typename T::const_iterator ite = X.end();
	if (Y == "print_full")
	{
		while (it != ite)
		{
			cout << "\n" << (*it).first << "\t";
			Show_cont(it->second);
			++it;
		}
	}
	else
	{
		while (it != ite)
		{
			if ((*it).first != Y)
			{
				++it;
			}
			else
			{
				cout << "\n" << (*it).first << "\t";
				Show_cont(it->second);
				++it;
			}
		}
	}
}

ostream& operator << (ostream& os, multimap<string, multiset<string>> X)
{
	multimap<string, multiset<string>>::const_iterator it = X.begin();
	multimap<string, multiset<string>>::const_iterator ite = X.end();
	while (it != ite)
	{
		cout << endl;
		os << "\n" << (*it).first << "\t";
		Show_cont(it->second);
		++it;
	}
	return os;
}
