
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


template <typename T> void print_V(T& X)
{
	auto y = X.begin();
	while (y != X.end())
	{
		cout << *y << " ";
		++y;
	}
}
template <typename T> void PrintAnyCont(const T& a)
{
	cout << endl;
	for (const auto& y : a) { cout << y << " "; };
}

string& operator- (string& A)
{
	for (auto& z : A)
	{
		if (islower(z))
		{
			z = toupper(z);
		}
		else if (isupper(z))
		{
			z = tolower(z);
		}
	}
	return A;
}

template <typename T> void NegateAll( T& X)
{
	 for (auto& y : X) { y = - y; }
	 
}

string& operator++ (string& Z)
{
	for (auto& z : Z)
	{
		++z;
	}
	return Z;
}

template <typename T> void IncAnyCont(T& X)
{
	for (auto& y : X) { ++y; }
}

template <typename T> void absSort(T& X)
{
	sort(begin(X), end(X), [](const auto& y, const auto& z) { return abs(z) > abs(y); });
}

template <typename T, typename W> auto SumCont(const T& X, const W& Y)
{
	size_t m = max(std::size(X), std::size(Y));
	vector <decltype(*begin(X) + *begin(Y))> d_V1(m);
	
	copy(begin(X), end(X), begin(d_V1));
	
	transform(begin(Y), end(Y), begin(d_V1), begin(d_V1), [](auto&y, auto&x) {return y + x; });
	return d_V1;
}

template <typename T, typename T1, typename T2, typename condition> void Separate(const T& one, T1& two, T2& three, condition c)
{
	for (const auto& a : one)
	{
		if (c(a))
			two.insert(end(two), a);
		else 
			three.insert(end(three), a);
	}
}

template <typename T, typename T1, typename T2, typename condition> void Separate1(const T& one, T1& two, T2& three, condition c)
{
	copy_if(cbegin(one), cend(one), inserter(two, begin(two)), c);
	copy_if(cbegin(one), cend(one), inserter(three, begin(three)), [c](const auto&x) { return !c(x); });

}

enum COLORS { red, green, blue };
auto stringToEnum(const char* A)
{
	if (static_cast<COLORS>(*A) == COLORS::blue)
		cout << "cool";
	return COLORS::blue;
}
