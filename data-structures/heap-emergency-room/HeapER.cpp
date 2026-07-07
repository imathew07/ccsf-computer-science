// Mateo Sanchez Sinche, CS 110C

#include "HeapER.h"

// Formulas for child and parent indices
int HeapER::getLeftChildIndex(int i) const
{
    return 2 * i + 1;
}

int HeapER::getRightChildIndex(int i) const
{
    return 2 * i + 2;
}

int HeapER::getParentIndex(int i) const
{
    return (i - 1) / 2;
}

bool HeapER::isLeaf(int i) const
{
    return getLeftChildIndex(i) >= itemCount;
}

// Converts a semiheap to a heap.
void HeapER::heapRebuild(int rootIndex)
{
    if (!isLeaf(rootIndex)) {
        int leftChild = getLeftChildIndex(rootIndex);
        int rightChild = getRightChildIndex(rootIndex);

        int largerChild = leftChild;

        if (rightChild < itemCount && items[rightChild] > items[leftChild]) {
            largerChild = rightChild;
        }

        if (items[rootIndex] < items[largerChild]) {
            swap(items[rootIndex], items[largerChild]);
            heapRebuild(largerChild);
        }
    }
}

// Creates a heap from an unordered array.
void HeapER::heapCreate()
{
    for (int i = (itemCount / 2) - 1; i >= 0; i--) {
        heapRebuild(i);
    }
}

// Constructors and destructor:
HeapER::HeapER()
{
    items = new Patient[DEFAULT_CAPACITY];
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
}

HeapER::HeapER(const Patient someArray[], const int arraySize)
{
    items = new Patient[DEFAULT_CAPACITY];
    itemCount = arraySize;
    maxItems = DEFAULT_CAPACITY;
    for (int i = 0; i < arraySize; i++) {
        items[i] = someArray[i];
    }
    heapCreate();
}

HeapER::~HeapER()
{
    delete[] items;
}

// Public methods:
bool HeapER::isEmpty() const
{
    return itemCount == 0;
}

int HeapER::getNumberOfNodes() const
{
    return itemCount;
}

int HeapER::getHeight() const
{
    if (itemCount == 0)
        return 0;
    int height = 0;
    int nodesAtLevel = 1;
    while (nodesAtLevel <= itemCount) {
        height++;
        nodesAtLevel *= 2;
    }
    return height;
}

Patient HeapER::peekTop() const
{
    if (isEmpty()) {
        throw PrecondViolatedExcep("peekTop() called on an empty heap.");
    }
    return items[ROOT_INDEX];
}

bool HeapER::add(const Patient& newPatient)
{
    if (itemCount == maxItems)
        return false;

    // Insert at bottom
    items[itemCount] = newPatient;

    // Trickle up
    int index = itemCount;
    bool inPlace = false;

    while (index > 0 && !inPlace) {
        int parent = getParentIndex(index);

        if (items[index] > items[parent]) {
            swap(items[index], items[parent]);
            index = parent;
        }
        else {
            inPlace = true;
        }
    }

    itemCount++;
    return true;
}

bool HeapER::remove()
{
    if (itemCount == 0)
        return false;

    // Move last to root
    items[0] = items[itemCount - 1];
    itemCount--;

    // Fix heap
    heapRebuild(0);

    return true;
}

void HeapER::clear()
{
    itemCount = 0;
}