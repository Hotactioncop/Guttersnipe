#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <string>



MyString::MyString(const char*smth)
{
	number = new char[strlen(smth) + 1];
	strcpy(number, smth);
}

MyString::MyString(MyString&&other)
{
	number = other.number;
	other.number = nullptr;
}

MyString::MyString(const MyString&other)
{
	// онвелс бейрнп ме янгдюер детнкрмши щкелемр опх ецн пеюкхгюжхх?
	//if (number)
	//	delete number;
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
}

MyString& MyString::operator= (MyString&other)
{
	if (number != nullptr)
		delete[]number;
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
	return *this;
}

MyString& MyString::operator= (MyString&&other)
{
	delete[]number;
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
	other.number = nullptr;
	return *this;
}

MyString& MyString::operator= (const char*smth)
{
	if (number != smth)
	{
		delete[]number;
		number = new char[strlen(smth) + 1];
		strcpy(number, smth);
		return *this;
	}
	return *this;
}

MyString::~MyString()
{
	delete[] number;
}

bool MyString::operator== (const char* other)
{
	return (strcmp(number, other) == 0);
}
