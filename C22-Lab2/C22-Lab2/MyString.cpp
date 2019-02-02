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
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
}

MyString& MyString::operator= (const MyString&other)
{
	if (number != nullptr)
		delete[]number;
	number = new char[strlen(other.number) + 1];
	strcpy(number, other.number);
	return *this;
}

MyString& MyString::operator= (MyString&&other)
{
	if (number != nullptr)
		delete[]number;
	number = other.number;
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
	if(number)
		delete[] number;
}


bool MyString::operator == (const MyString& other)
{
	return !(strcmp(number, other.number));
}

bool MyString::operator != (const MyString& other)
{
	return strcmp(number, other.number);
}

char* MyString::GetString() const
{
	return number;
}

void MyString::SetNewString(const char* smth)
{
	if (strcmp(number, smth) != 0)
	{
		delete[]number;
		number = new char[strlen(smth) + 1];
		strcpy(number, smth);
	}
}