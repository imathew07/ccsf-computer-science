// Mateo Sanchez Sinche, CS 110 C

#ifndef NODE_H
#define NODE_H

#include "Person.h"

class Node {
public:
    Person data;
    Node* left;
    Node* right;

    Node(Person p) : data(p), left(nullptr), right(nullptr) {}
};

#endif