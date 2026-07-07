// Mateo Sanchez Sinche, CS 110C

#ifndef _HEAPER_H_
#define _HEAPER_H_

#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"
#include "Patient.h"

class HeapER {
private:
    static const int ROOT_INDEX = 0; // Helps with readability
    static const int DEFAULT_CAPACITY = 21; // Small capacity to test
    Patient* items;
    int itemCount;
    int maxItems;

	// Formulas for child and parent indices
    int getLeftChildIndex(int i) const;
    int getRightChildIndex(int i) const;
    int getParentIndex(int i) const;

    bool isLeaf(int i) const;

    void heapRebuild(int rootIndex);
	void heapCreate();

public:
	// Constructors and destructor:
    HeapER();
	HeapER(const Patient someArray[], const int arraySize);
	virtual ~HeapER();

	// HeapInterface Public Methods:
	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
    Patient peekTop() const;
    bool add(const Patient& newPatient);
    bool remove();
	void clear();
};

#endif