#pragma once
#include <iostream>
using namespace::std;

class MyString
{
	char*number;
public:
	MyString(const char *smth = "Queen");
	MyString(MyString&&);
	MyString(const MyString&);
	MyString& operator= (MyString&other);
	MyString& operator= (MyString&&);
	MyString& operator= (const char*smth);
	bool operator== (const char* other);
	friend ostream& operator<< (ostream& os, const MyString& my)
	{
		os << my.number;
		return os;
	}
	friend char& check(const MyString&x)
	{
		return x.number[0];
	}

	~MyString();
};