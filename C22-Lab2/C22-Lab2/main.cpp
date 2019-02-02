#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Header.h"
#include "MyString.h"
#include "MyQueue.h"
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include "MyUniquePTR.h"
#include <memory>



using namespace std;
#define stop __asm nop


MyQueue< MyString> Cool(MyString& a)
{
	MyQueue< MyString> Z{ a };
	return Z;
}
int main()
{
		setlocale(LC_ALL, "RUSSIAN");
	{
	MyQueue<MyString>  q1{ MyString("AAA"), MyString("qwerty") };
	cout << q1;

	MyString s("abc");
	MyString e("abc");
	MyString d("abc");
	MyString f("abc");
	MyString g("abc");
	MyString h("abc");
	MyString j("abc");
	MyString k("abc");
	MyString l("edf");
	MyString m("zxc");

	q1.push(s);
	q1.push(e);
	q1.push(d);
	q1.push(f);
	q1.push(g);
	q1.push(h);
	q1.push(j);
	q1.push(k);
	q1.push(l);
	q1.push(l);
	q1.push(l);
	q1.push(l);
	q1.push(l);
	cout << q1;

	q1.push(m);

	cout << q1;
	q1.push(MyString("123"));

	cout << q1;

	MyString s1 = q1.pop();
	cout << q1;

	q1.push("qqq");
	cout << q1;

	MyQueue < MyString >  q2 = q1;
	cout << q2;

	MyQueue<MyString>q3 {10, MyString("!") };
	cout << q3;

	q1 = q3;
	cout << q1;

	q2 = MyQueue < MyString >(5, MyString("?"));
	cout << q2;

	cout << q1;
	q1 = { MyString("bbb"), MyString("ssss") };
	cout << q1;

	q2 = q3;

	q2.push("!");
	q2.push("!");
	q2.pop();
	q2.pop();
	if (q2 == q3)
		cout << "\nEUREKA";

	q2.push("?");
	q2.pop();
	if (q2 == q3)
		cout << "\nEUREKA";
	else cout << "\nNot now, master...";

}
	//////////////////////////////////////////////////////////////////

	{
		MyUniquePTR<MyString> p1(new MyString("abc"));
		cout << p1;
		std::cout << p1->GetString();
		p1->SetNewString("qwerty");
		cout << p1;

		MyString  s2 = *p1;
		cout << s2;

		MyUniquePTR< MyString > p2 = move(p1);
		if (!p1)
		{
			std::cout << "No object!";
		}

		MyUniquePTR< MyString > p3(new MyString("vvv"));
		p3 = move(p2);


		vector< MyUniquePTR< MyString >>  v; //как проинициализировать???
		v.emplace_back(new MyString ("EEE"));
		list< MyUniquePTR< MyString >>  l;
		//как скопировать из v в l ???
		for (auto&x : v)
		{
			l.emplace_back(move(x));
		}
		//copy(make_move_iterator(v.begin()), make_move_iterator(v.end()), back_inserter(l));
		Show_me(l);

		stop
	}
	stop
}