#pragma once
#include "MyString.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

template <typename T>class MyUniquePTR
{
	T* ptr = nullptr;
public:
	MyUniquePTR()= default;
	MyUniquePTR(T* other);
	MyUniquePTR(MyUniquePTR& other) = delete;
	MyUniquePTR& operator= (MyUniquePTR& other) = delete;
	MyUniquePTR(MyUniquePTR&& other);
	T operator* ();
	T* operator->();
	operator bool();
	MyUniquePTR& operator = (MyUniquePTR&& other);
	friend ostream& operator << (ostream& os, MyUniquePTR<T>& other)
	{
		os << endl;
		os << *other.ptr;
		return os;
	}
	~MyUniquePTR() { delete ptr; };
};

template<typename T>
inline MyUniquePTR<T>::MyUniquePTR(T * other)
{
	ptr = other;
}

template<typename T>
MyUniquePTR<T>::MyUniquePTR(MyUniquePTR && other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
T MyUniquePTR<T>::operator*()
{
	return *ptr;
}

template<typename T>
T * MyUniquePTR<T>::operator->()
{
	return ptr;
}

template<typename T>
MyUniquePTR<T>::operator bool()
{
	return (ptr != nullptr);
}

template<typename T>
MyUniquePTR<T>& MyUniquePTR<T>::operator=(MyUniquePTR && other)
{
	if (ptr == other.ptr)
		return *this;
	delete ptr;
	ptr = other.ptr;
	other.ptr = nullptr;
	return *this;
}
