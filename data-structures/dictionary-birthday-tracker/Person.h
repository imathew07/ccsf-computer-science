// Mateo Sanchez Sinche, CS 110 C

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    int month;
    int day;

public:
    // Constructors
    Person();
    Person(std::string n, int m, int d);

    // Getters
    std::string getName() const { return name; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

	// Method to print the person's information
    void print() const;
};

#endif