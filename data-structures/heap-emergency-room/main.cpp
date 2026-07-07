// Mateo Sanchez Sinche, CS 110C

#include "HeapER.h"
#include <iostream>
using namespace std;

int main()
{
    HeapER ER;

    ER.add(Patient(5, "Bob"));
    ER.add(Patient(9, "Mary"));
    ER.add(Patient(1, "Max"));

    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();

    ER.add(Patient(3, "Julio"));
    ER.add(Patient(7, "Stacy"));
    ER.add(Patient(4, "Paul"));
    ER.add(Patient(2, "Reiko"));
    ER.add(Patient(6, "Jennifer"));
    ER.add(Patient(5, "Chang"));

    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();

    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();

    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();

    return 0;
}

/* SAMPLE OUTPUT:
9 Mary will now see the doctor.
7 Stacy will now see the doctor.
6 Jennifer will now see the doctor.
5 Bob will now see the doctor.
*/