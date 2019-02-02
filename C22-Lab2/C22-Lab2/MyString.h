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
	MyString& operator= (const MyString&other);
	MyString& operator= (MyString&&);
	MyString& operator= (const char*smth);
	char* GetString() const;
	void SetNewString(const char* smth);
	bool operator == (const MyString& other);
	bool operator != (const MyString& other);

	friend ostream& operator<< (ostream& os, MyString& my)
	{
		os << my.number;
		return os;
	}

	~MyString();
};