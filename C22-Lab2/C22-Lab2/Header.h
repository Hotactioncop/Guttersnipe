#pragma once
using namespace std;
#include <iostream>
#include <ostream>

template <typename T> void Show_me(T& other)
{
	cout << endl;
	for (auto&x : other)
		cout << x << " ";
}