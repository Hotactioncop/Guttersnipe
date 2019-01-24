//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include <vector>
#include "MyString.h"
#include "Point.h"
#include <iterator>
#include <list>
#include <deque>

#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop

template <typename T> void Sort(vector<T>& other)
{
	typename vector<char>::iterator it = other.begin();
	typename vector<char>::iterator his = other.begin();
	while (it != other.end())
	{
		++his;
		while (his != other.end())
		{
			if (*it == *his)
			{
				his = other.erase(his);
			}
			else
				++his;
		}
		++it;
		his = it;
	}
}


template <typename T> void sizes(const vector<T>& other)
{
	cout << endl;
	cout << "Size: " << other.size() << endl;
	cout << "Capacity: " << other.capacity() << endl;
	cout << "Max_size: " << other.max_size() << endl;
	cout << "�������� ������� ���������: ";
	for (int i = 0; i < other.size(); i++)
		cout << other[i] << "\t";
}
template <typename T> void sizes(const vector<T*>& other)
{
	cout << endl;
	cout << "Size: " << other.size() << endl;
	cout << "Capacity: " << other.capacity() << endl;
	cout << "Max_size: " << other.max_size() << endl;
	cout << "�������� ������� ���������: ";
	for (int i = 0; i < other.size(); i++)
		cout << *other[i] << "\t";
}
template <typename T> ostream& operator << (ostream& os, const vector<T>& other)
{
	for (int i = 0; i < other.size(); i++)
	{
		os << other[i] <<" ";
	}
	return os;
}

void deletes(vector<char>& other)
{
	vector<char>::iterator it = other.begin();
	vector<char>::iterator his = other.begin();
	while (it != other.end())
	{
		++his;
		while (his != other.end())
		{
			if (*it == *his)
			{
				his = other.erase(his);
			}
			else
				++his;
		}
		++it;
		his = it;
	}
}


void delete_copy(vector <char>& other)
{
	vector<char>::iterator his = other.begin();
	vector<char>::iterator it = other.begin();
	while (it != other.end())
	{
		++his;
		while (his != other.end())
		{
			if (*it == *his)
			{
				his = other.erase(his);
			}
			else
				++his;
		}
		++it;
		his = it;
	}
}

template <typename T> void Showme(const T&x)
{
	typename T::const_iterator it = x.begin();
	cout << endl;
	while (it != x.end())
	{
		cout << *it << " ";
		++it;
	}
}

bool operator < (const Point& first, const Point& second)
{
	return ((pow(first.one, 2) + pow(first.two, 2)) < (pow(second.one, 2) + pow(second.two, 2)));
}

bool Neg(const Point& other) 
{
	return ((other.one < 0) && (other.two < 0));
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	vector<int> vInt;
	cout << vInt.size();

	
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������
	vInt.push_back(5);
	vInt.front()=1;

	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	vInt.push_back(11);
	sizes(vInt);
	vInt.push_back(32);
	sizes(vInt);
	vInt.push_back(145);
	sizes(vInt);



	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	vector<double> vDouble1(5);
	sizes(vDouble1);


	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 
	vector< MyString> vMyString(5, "A");
	sizes(vMyString);
	vMyString.at(0) = "Best";
	vMyString.at(1) = "Friends";
	vMyString.at(2) = "Forever";
	vMyString.at(3) = "End";
	vMyString.at(4) = "Ever";
	sizes(vMyString);
	//vMyString.at(5) = "Let's try this";
	sizes(vMyString);
	vMyString[0] = "Check 0";
	sizes(vMyString);
	//vMyString[5] = "Check 5";

	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!
	vector<double> dMas(6);
	sizes(dMas);
	dMas[0] = 0.1;
	dMas[1] = 0.2;
	dMas[2] = 0.3;
	dMas[3] = 0.4;
	dMas[4] = 0.5;
	dMas[5] = 0.6;

	sizes(dMas);
	vector<double> vDouble3(dMas.begin(), dMas.begin()+5);
	sizes(vDouble3);

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	vector<double> vDouble4(dMas.begin()+2, dMas.begin() + 5);
	sizes(vDouble4);


	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?   ���������, ����������� � ����������� ������ Point.
	vector<Point> vPoint1(3);
	sizes(vPoint1);

	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	vector<Point> vPoint2(5, Point(1,1));
	sizes(vPoint2);

	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		//vector<Point*> vpPoint(5);
		//for (int i = 0; i < 5; i++)
		//	vpPoint[i] = &vPoint2[i];
		//sizes(vpPoint);
		vector<MyString*> vpPoint(5);
		char g []= "a";
		for (int i = 0; i < 5; i++)
		{
			(*g)++;
			vpPoint[i] = new MyString(g);
		}
		sizes(vpPoint);


	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

	}//����� �������������� �������� ����� ����������� ��� ������ �������?


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
		{
		size_t n = 1;
		vector<int> v(n);
		v.resize(n/2);
		if (v.capacity() == n)
			cout << "I'm true";		//true?  true
		}
		/**/

		
		{
			int n = 101;
			size_t m = 100;
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) 
			cout << "I'm true";		//true? �� ������. n ������ ���� >=0; ������� �� �����������, ���� n>m;
		}
		/**/

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������? 3 3 3 10
		v.resize(5); //��������? 3 3 3 10 0
		}
		/**/

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������
		vector<char> vOne;
		vector<char> vTwo;
		vOne.reserve(5);

		char b = 65;
		for (int i = 0; i < 5; i++)
			vOne.push_back(b++);
		sizes(vOne);

		b = 65;
		for (int i = 0; i < 5; i++)
			vTwo.push_back(b++);				// Capacity ������ �� 1. Size - ���������.
		sizes(vTwo);

		stop;



	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.
		vTwo.shrink_to_fit();
		sizes(vTwo);
	
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
		int ar[] = { 11,2,4,3,5 };
		vector <vector <int> > vv(5);

		for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); i++)
		{
			vv[i].resize(ar[i]);
			for (int j = 0; j < ar[i]; j++)
				vv.at(i).at(j) = ar[i];
		}
		std::cout << vv;

	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.
		vector<char> vChar2(5);
	 vector<char>::iterator it = vChar2.end();
	 char c = 'A';
	 for (int i = 0; i < 5; i++)
		 vChar2[i] = c++;
	 sizes(vChar2);
	 c = 'F';
	 int a = 4;
	 while (it != vChar2.begin())
	 {
		 if (*(--it) == c)
		 {
			 break;
		 }
		 if(it == vChar2.begin())
			 it = vChar2.insert(it, c);
	 }
	 sizes(vChar2);

	 stop;

	
	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	it = vChar2.begin();
	while (it != vChar2.end())
	{
		it = vChar2.insert(it, c);
		it+=2;
	}
	sizes(vChar2);
	stop;


///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	vector <char> vWord1;
	char qr[] = { 'q','w','e','r','r','r','r','2','t','y','1','2','2','2','2','r','3' };
	vWord1.resize(sizeof(qr) / sizeof(qr[0]));
	for (int i = 0; i < sizeof(qr) / sizeof(qr[0]); i++)
		vWord1[i] = qr[i];
	sizes(vWord1);
	vector<char>::iterator me = vWord1.begin();
	vector<char>::iterator his = vWord1.begin();
	deletes(vWord1);
	vWord1.shrink_to_fit();
	sizes(vWord1);
	stop

		///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 
		vector <char> vWord3;
	char sr[] = { 'q','w','e','r','r','r','r','2','t','y','1','2','2','2','2','r','3' };
	vWord3.resize(sizeof(sr) / sizeof(sr[0]));
	for (int i = 0; i < sizeof(sr) / sizeof(sr[0]); i++)
		vWord3[i] = sr[i];
	sizes(vWord3);
	Sort(vWord3);
	vWord3.shrink_to_fit();
	sizes(vWord3);
	stop





		///////////////////////////////////////////////////////////////////
			//�������� ����� ������ ����� �������, ����� ��� �������� �����
			//������� ��������� ������ �� ��������� ����� ��������, �� �����������
			//���� �� � �������� �������
	vector<char> vWord4;
	vector<char>::reverse_iterator rit = vWord3.rbegin();
	while (rit != vWord3.rend())
	{
		vWord4.push_back(*rit);
		++rit;
	}
	sizes(vWord4);


///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	list<Point> ptList1;
	ptList1.push_back(Point(1, 2));
	ptList1.push_front(Point(5, 5));

	list<Point>::iterator itr = ptList1.begin();
	ptList1.insert(itr, Point(4, 3));


	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
	Showme(vWord4);
	Showme(ptList1);

	//�������� ����� �� ������� "�����������" - reverse()
	
	ptList1.reverse();
	Showme(ptList1);

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 
	list<Point> ptList2;
	vector<Point> vtVect;
	vtVect.push_back(Point(1, 1));
	vtVect.push_back(Point(2, 2));
	vtVect.push_back(Point(3, 3));
	vtVect.push_back(Point(4, 4));
	vtVect.push_back(Point(5, 5));
	sizes(vtVect);
	vector<Point>::reverse_iterator rit1 = vtVect.rbegin();
	while (rit1 != vtVect.rend())
	{
		ptList2.push_back(*rit1);
		++rit1;
	}
	Showme(ptList2);

	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	Showme(ptList1);

	ptList2.sort();
	Showme(ptList2);

	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.
	ptList1.merge(ptList2);
	Showme(ptList1);

	ptList2.merge(ptList1);
	Showme(ptList2);

	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?

	ptList2.remove(Point(5, 5));
	Showme(ptList2);

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if().
	ptList2.push_back(Point(-3, -5));

	ptList1.remove_if(Neg);
	Showme(ptList2);


	//���������� �� ������ ������ ������������� ������ - unique(). 
	ptList2.push_back(Point(6, 6));
	ptList2.push_back(Point(6, 6));
	ptList2.unique();
	Showme(ptList2);
	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
		deque<Point> myDeque;
	myDeque.assign(ptList2.begin(), ptList2.end());
	Showme(myDeque);




	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	deque<MyString> myDeque2;
	myDeque2.push_back("AAA");
	myDeque2.push_back("BCD");
	myDeque2.push_front("aed");
	myDeque2.push_front("Caf");
	myDeque2.insert(myDeque2.end(),"Dog");
	Showme(myDeque2);
	deque<MyString>::iterator dit = myDeque2.begin();
	while (dit != myDeque2.end())
	{
		if (check(*dit) == 'a' || check(*dit) == 'A')
		{
			dit = myDeque2.erase(dit);
		}
		else
			++dit;
	}
	Showme(myDeque2);



	stop
	return 0;
}