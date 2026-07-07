//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h
    Listing 4-1 */

// Mateo Sanchez Sinche, CS 110C, Assignment 3
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node
	Node<ItemType>* prev; // Pointer to previous node (for doubly linked list)

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
	void setPrev(Node<ItemType>* prevNodePtr); // New method for doubly linked list
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
	Node<ItemType>* getPrev() const; // New method for doubly linked list
}; // end Node

#endif