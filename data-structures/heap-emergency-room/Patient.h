// Mateo Sanchez Sinche, CS 110C
// Extra Credit

#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int priority;
    string name;
public:
    Patient();
    Patient(int p, string n);

    // Overload > for maxheap
    bool operator>(const Patient& other) const;

	// Overload < for minheap
    bool operator<(const Patient& other) const;

    // Printing
    friend ostream& operator<<(ostream& os, const Patient& p);
};

#endif