// Mateo Sanchez Sinche, CS 110 C

#include "Person.h"

Person::Person()
{
	name = "";
	month = 0;
	day = 0;

}

Person::Person(std::string n, int m, int d)
{
	name = n;
	month = m;
	day = d;
}

void Person::print() const
{
	std::cout << name << " - " << month << "/" << day << std::endl;
}