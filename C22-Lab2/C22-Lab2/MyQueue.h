#pragma once
#include "MyString.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <queue>

using namespace std;

template <typename T>class MyQueue
{
public:
	T* m_cur;
	size_t m_first, m_last;
	size_t m_cap, m_n;

	MyQueue(const MyQueue& other);
	MyQueue(MyQueue&& other);
	MyQueue(size_t capa, T other);
	MyQueue(initializer_list<T> other);
	template <typename TT> void push(TT&& other);
	MyQueue& operator= (const MyQueue& other);
	MyQueue& operator= (MyQueue&& other);
	MyQueue& operator= (initializer_list<T> other);
	bool operator== (const MyQueue& other) const;
	inline friend ostream& operator<< (ostream& os, MyQueue<T>& other)
	{
		os << endl;
		int me = other.m_first;
		for (int i = 0; i < other.m_n; i++)
		{
			os << other.m_cur[me%other.m_cap] << " ";
			++me;
		}

		return os;
	}
	T pop();
	~MyQueue() { delete[] m_cur; };
};

template <typename T>
MyQueue<T>::MyQueue(const MyQueue& other) :m_n(other.m_n), m_first(other.m_first), m_last(other.m_last), m_cap(other.m_n)
{
	m_cur = new T[m_n];
	for (int i = 0; i < m_n; i++)
	{
		m_cur[i] = other.m_cur[i];
	}
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue&& other) :m_cap(other.m_cap), m_first(other.m_first), m_n(other.m_n), m_last(other.m_last)
{
	m_cur = other.m_cur;
	other.m_cur = nullptr;
}

template <typename T>
MyQueue<T>::MyQueue(size_t capa, T other)
{
	m_cur = new T[capa];
	m_cap = m_n = capa;
	for (size_t i = 0; i < m_n; i++)
	{
		m_cur[i] = other;
	}
	m_first = 0;
	m_last = (m_first + m_n) % m_cap;
}


template <typename T>
MyQueue<T>::MyQueue(initializer_list<T> other)
{
	m_n = size(other);
	m_cap = m_n + 1;
	m_cur = new T[m_cap];
	size_t i = 0;
	for (auto&x : other)
	{
		m_cur[i] = move(x);
		++i;
	}
	m_first = 0;
	m_last = i;
}

template <typename T>
T MyQueue<T>::pop()
{
	T ret = std::move(m_cur[m_first]);
	++m_first;
	--m_n;
	m_first = m_first % m_cap;

	return ret;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator= (const MyQueue& other)
{
	if (m_cap <= other.m_n)
	{
		delete[] m_cur;
		m_cur = new T[other.m_n];
	}
	m_cap = m_n = other.m_n;
	int ifirst = other.m_first;
	for (int i = 0; i < other.m_n; i++)
	{
		m_cur[i] = other.m_cur[ifirst%other.m_cap];
		++ifirst;
	}
	m_first = 0;
	m_last = (m_first + m_n) % m_cap;
	return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator= (MyQueue&& other)
{
	if (m_cap <= other.m_n)
	{
		delete[] m_cur;
		m_cur = new T[other.m_n];
	}
	m_cap = m_n = other.m_n;
	int ifirst = other.m_first;
	for (int i = 0; i < other.m_n; i++)
	{
		m_cur[i] = move(other.m_cur[ifirst%other.m_cap]);
		++ifirst;
	}
	m_first = 0;
	m_last = (m_first + m_n) % m_cap;
	return *this;
}


template <typename T>
MyQueue<T>& MyQueue<T>::operator= (initializer_list<T> other)
{
	if (m_cap < size(other))
	{
		delete[] m_cur;
		m_cur = new T[size(other)];
	}
	m_cap = m_n = size(other);
	size_t i = m_first = 0;
	for (auto x : other)
	{
		m_cur[i] = move(x);
		++i;
	}
	m_last = (m_first+m_n)%m_cap;
	return *this;
}

template<typename T>
template<typename TT>
inline void MyQueue<T>::push(TT && other)
{
	if (m_n == m_cap)
	{
		T* ptr = new T[m_cap+2];
		for (int i = 0; i < m_n; i++)
		{
			ptr[i] = move(m_cur[m_first%m_cap]);
			++m_first;
		}
		m_first = 0;
		m_cap += 2;
		m_last = (m_first + m_n) % m_cap;
		delete[]m_cur;
		m_cur = ptr;
		ptr = nullptr;
	}
	m_cur[m_last] = std::forward<TT>(other);
	++m_n;
	m_last = (m_first + m_n) % m_cap;
}

template <typename T>
bool MyQueue<T>::operator== (const MyQueue<T>& other) const
{
	if (m_n != other.m_n)
	{
		return false;
	}
	int me = m_first;
	int he = other.m_first;
	for (int i = 0; i < m_n; i++)
	{
		if (m_cur[me%m_cap] != other.m_cur[he%other.m_cap])
		{
			return false;
		}
		++me;
		++he;
	}
	return true;
}