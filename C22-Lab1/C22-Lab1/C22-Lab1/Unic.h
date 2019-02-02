#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <tuple>


using namespace std;

enum how {ascending, descending};

template <typename T> class Unic
{
protected:
	vector<T> im_vec;
	typename T lower;
	typename T upper;
public:
	Unic(const initializer_list<T>& other, const T& low, const T& up )
	{
		im_vec.reserve(size(other));
		for_each(begin(other), end(other), [&](auto&x)
		{
			if (x >= low && x <= up)
			{
				for (auto&z : im_vec)
				{
					if (x == z)
						return;
				}
				im_vec.push_back(x);
			}
		});
	}
	inline friend ostream& operator<< (ostream& os, Unic& other)
	{
		for_each(begin(other.im_vec), end(other.im_vec), [&](const auto& x) {os << x << " "; });
		return os;
	}

	void Add_it(const initializer_list<T>& other, const T& low, const T& up)
	{
		for_each(begin(other), end(other), [&](auto&x)
		{
			if (x >= low && x <= up)
			{
				for (auto&z : im_vec)
				{
					if (x == z)
						return;
				}
				im_vec.push_back(x);
			}
		});
	}

	void Pop_it(initializer_list<T> other)
	{
		for_each(begin(other), end(other),[&](auto&x)
		{
			auto it = begin(im_vec);
			while (it!=end(im_vec))
			{
				if (x == *it)
				{
					im_vec.erase(it);
					return;
				}
				++it;
			}
		});
	}
	~Unic() {};

	void Sort_it(const how& x)
	{
	
		sort(im_vec.begin(), im_vec.end(), [x](auto&y, auto&z) {return(x == ascending) ? (y < z) : (y > z); });
		
	}
};

