#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

constexpr int factorial(int a)
{
	if (a < 0)
		throw "error";
	return (a == 0) ? 1 : (a * factorial(a - 1));
}

constexpr int multb(const char* a, int b)
{
	return (*a == 0) ? b : multb(a + 1, (b << 1) + (*a - '0'));
}

constexpr unsigned long long operator"" _bb(const char* str)
{
	return multb(str, 0);
}

string make_bin(size_t repeats, string str, unsigned long long numb, unsigned long long check, bool flag)
{
	return (repeats == 0) ? ((flag == false) ? (((numb & check) == 0) ? str: str+'1'):(((numb & check) == 0) ? str+'0' : str+'1')):
		(flag == false)?(((numb& check)==0)?make_bin(repeats -1, str, numb, check>>1, false): make_bin(repeats - 1, str+'1', numb, check >> 1, true)):
		(((numb& check) == 0)?make_bin(repeats-1, str+'0',numb, check>>1, true):make_bin(repeats-1, str+'1', numb, check>>1, true));
}

string operator"" _toBinStr(unsigned long long numb)
{
	return make_bin(31, "0b", numb, 0x80000000, false);
}

inline ostream& operator << (ostream& os, vector<string*>& other)
{
	os << endl;
	for (auto*x : other)
		os << *x << " ";
	return os;
}

inline ostream& operator << (ostream& os, vector<unique_ptr<string>>& other)
{
	os << endl;
	for (auto&x : other)
	{
		if (x.get() == nullptr) {}
		else os << *x.get();
	}
	return os;
}

void Add_suff(vector<unique_ptr<string>>& other, string str)
{
	for (auto&x : other)
	{
		if (x.get() == nullptr) {}
		else *x = *x + str;
	}
}

void deltr(string* other[])
{
	for (int i = 0; i<sizeof(other)/sizeof(other[0]); i++)
		delete other[i];
}