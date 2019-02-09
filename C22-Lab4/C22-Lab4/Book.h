#pragma once
#include<iostream>
#include <string>
#include <tuple>
#include <ostream>

using namespace std;

class Book
{
	tuple <string, string, int> b_book;
public:
	Book(string A, string B, int C);
	bool operator< (const Book& other) const;
	bool operator> (const Book& other) const;
	bool operator== (const Book& other) const;
	bool operator!= (const Book& other) const;
	friend ostream& operator <<(ostream&os, const Book&other)
	{
		os << get<0>(other.b_book) << "\n" << get<1>(other.b_book) << "\n" << get<2>(other.b_book) << endl;
		return os;
	}

	~Book();
};

