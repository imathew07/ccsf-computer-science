//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

// Mateo Sanchez Sinche, CS 110C, Assignment 3

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
    headPtr = nullptr;
	tailPtr = nullptr;
    itemCount = 0;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
    : headPtr(nullptr), tailPtr(nullptr), itemCount(aList.itemCount)
{
    Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
    {
        headPtr = nullptr;  // Original list is empty
		tailPtr = nullptr;  // Set tailPtr to nullptr for empty list
    }
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            newNodePtr->setPrev(newChainPtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of chain
        tailPtr = newChainPtr;                      // Set tailPtr to last node
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        // First node in the list
        if (itemCount == 0)
        {
			headPtr = tailPtr = newNodePtr;
        }
        // Special case for inserting at beginning of list
        else if (newPosition == 1)
        {
            // Insert new node at beginning
            newNodePtr->setNext(headPtr);
			headPtr->setPrev(newNodePtr);
            headPtr = newNodePtr;
        }
        // Special case for inserting at end of list
        else if (newPosition == itemCount + 1)
        {
			newNodePtr->setPrev(tailPtr);
			tailPtr->setNext(newNodePtr);
			tailPtr = newNodePtr;
        }
        // Normal case for inserting in the middle of the list
        else
        {
			// Find node that will be before new node
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			Node<ItemType>* nextPtr = prevPtr->getNext();

			// Insert new node between prevPtr and nextPtr
            newNodePtr->setNext(nextPtr);
			newNodePtr->setPrev(prevPtr);

			// Update links of nodes before and after new node
            prevPtr->setNext(newNodePtr);
			nextPtr->setPrev(newNodePtr);
        }

        itemCount++;  // Increase count of entries
    }  // end if

    return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;

        // Remove the first node in the chain
        if (itemCount == 1)
        {
            curPtr = headPtr; // Save pointer to node
            headPtr = nullptr;
			tailPtr = nullptr;
        }
		// Special case for removing the first node
        else if (position == 1)
        {
			curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();

			// Update the previous pointer of the new head node
            if (headPtr != nullptr)
                headPtr->setPrev(nullptr);
        }
        // Remove the last node in the chain
        else if (position == itemCount)
        {
            curPtr = tailPtr; // Save pointer to node
			tailPtr = tailPtr->getPrev();

			// Update the next pointer of the new tail node
            if (tailPtr != nullptr)
                tailPtr->setNext(nullptr);
        }
		// Normal case for removing a node in the middle of the list
		else
        {
			curPtr = getNodeAt(position); // Save pointer to node
			Node<ItemType>* prevPtr = curPtr->getPrev();
			Node<ItemType>* nextPtr = curPtr->getNext();

			prevPtr->setNext(nextPtr); // Update the previous node's next pointer
			nextPtr->setPrev(prevPtr); // Update the next node's previous pointer
        }  // end if

        // Return node to system
        curPtr->setNext(nullptr);
		curPtr->setPrev(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else
    {
        string message = "setEntry() called with an invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

template<class ItemType>
void LinkedList<ItemType>::reverse()
{
	// Debugging check of precondition
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* temp = nullptr;

	// Traverse the list and swap the next and previous pointers of each node
    while (curPtr != nullptr)
    {
        temp = curPtr->getPrev();
        curPtr->setPrev(curPtr->getNext());
        curPtr->setNext(temp);
        curPtr = curPtr->getPrev();
    }

    // After the loop, temp will be pointing to the new head of the list
    temp = headPtr;
    headPtr = tailPtr;
    tailPtr = temp;
}


// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;