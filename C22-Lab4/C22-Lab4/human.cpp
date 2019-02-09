#include "human.h"




human::human(human & other)
{
	name = other.name;
	alive = other.alive;
}

human::human(human && other)
{
	name = move(other.name);
	alive = move(other.alive);
}

human & human::operator=(human & other)
{
	name = other.name;
	alive = other.alive;
	return *this;
}

human & human::operator=(human && other)
{
	name = move(other.name);
	alive = move(other.alive);
	return *this;
}

human human::child(const string& smb, live m, human * first, human * second)
{
	shared_ptr<human> ptr = make_shared<human>(new human(smb, m));
	weak_ptr rtr = ptr;
	first->child = rtr;
	second->child = rtr;
	first->child.mom = first;
	return *ptr;
}

human::~human()
{
}
