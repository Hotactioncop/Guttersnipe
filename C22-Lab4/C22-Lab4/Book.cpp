#include "Book.h"





Book::Book(string A, string B, int C)
{
	b_book = make_tuple(A, B, C);
}

bool Book::operator<(const Book& other) const
{
	return (b_book <other.b_book)?true:false;
}

bool Book::operator>(const Book& other) const
{
	return (b_book>other.b_book)?true:false;
}

bool Book::operator==(const Book& other) const
{
	return (b_book==other.b_book)?true:false;
}

bool Book::operator!=(const Book& other) const
{
	return (b_book!=other.b_book)?true:false;
}

Book::~Book()
{
}
