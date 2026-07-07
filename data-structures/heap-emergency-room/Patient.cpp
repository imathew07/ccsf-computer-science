// Mateo Sanchez Sinche, CS 110C

#include "Patient.h"

Patient::Patient()
{
	priority = 0;
	name = "";
}

Patient::Patient(int p, string n)
{
    priority = p;
    name = n;
}

bool Patient::operator>(const Patient& other) const
{
	return priority > other.priority;
}

bool Patient::operator<(const Patient& other) const
{
	return priority < other.priority;
}

ostream& operator<<(ostream& os, const Patient& p)
{
    os << p.priority << " " << p.name;
    return os;
}