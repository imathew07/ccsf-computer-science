// Mateo Sanchez Sinche, CS 110 C
// A C++ program to test a Dictionary to track the name and birthday of your friends and relatives

#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{
    Dictionary Birth;

    // Add entries
    Birth.add(Person("Alice", 3, 15));
    Birth.add(Person("Bob", 7, 22));
    Birth.add(Person("Charlie", 3, 10));
    Birth.add(Person("Diana", 12, 5));
    Birth.add(Person("Eve", 7, 1));

    cout << "=== All entries ===" << endl;
    Birth.displayAll();

    cout << "\n--- Search for Bob ---" << endl;
    Person* p = Birth.getItem("Bob");
    if (p != nullptr)
        p->print();
    else
        cout << "Not found" << endl;

    cout << "\n--- People born in July (Month 7) ---" << endl;
    Birth.displayByMonth(7);

    cout << "\n--- Removing Charlie ---" << endl;
    Birth.remove("Charlie");
    if (Birth.getItem("Charlie") == nullptr)
        cout << "Charlie successfully removed" << endl;
    else
		cout << "Failed to remove Charlie" << endl;

    cout << "\n--- All entries after removal ---" << endl;
    Birth.displayAll();

    cout << "\n--- Search for Charlie ---" << endl;
    p = Birth.getItem("Charlie");
    if (p != nullptr)
        p->print();
    else
        cout << "Not found" << endl;

    return 0;
}

/* SAMPLE OUTPUT:
=== All entries ===
Alice - 3/15
Bob - 7/22
Charlie - 3/10
Diana - 12/5
Eve - 7/1

--- Search for Bob ---
Bob - 7/22

--- People born in July (Month 7) ---
Bob - 7/22
Eve - 7/1

--- Removing Charlie ---
Charlie successfully removed

--- All entries after removal ---
Alice - 3/15
Bob - 7/22
Diana - 12/5
Eve - 7/1

--- Search for Charlie ---
Not found
*/