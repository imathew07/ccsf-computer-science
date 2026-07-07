// Mateo Sanchez Sinche, CS 110 C

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Node.h"

class Dictionary {
private:
    Node* root;

    Node* insert(Node* node, Person p);
    Node* removeNode(Node* node, std::string name);
    Node* findMin(Node* node);

    Person* search(Node* node, std::string name);

    void inorder(Node* node);
    void searchByMonth(Node* node, int month);

public:
    Dictionary(); // Constructor
    bool add(Person p); // add an entry
    bool remove(std::string name); // remove an entry
    Person* getItem(std::string name); // // search the dictionary for the birthday for a given name
    void displayAll(); // display the name and birthday of every entry in the dictionary
    void displayByMonth(int month); // display everyone in the dictionary who was born in a given month
};

#endif