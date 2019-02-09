#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <set>

using namespace std;

enum live { no, yes };
class human
{
protected:
	string name;
	bool alive;
	shared_ptr<human> mom ;
	shared_ptr<human> dad ;
	weak_ptr<human> chil;
public:
	human(const string& smb, live m)
	{
		name = smb;
		alive = m;
	}
	human(human& other);
	human(human&& other);
	human& operator=(human& other);
	human& operator=(human&& other);
	static human child(const string& smb, live m, human* first, human* second);
	~human();
};

