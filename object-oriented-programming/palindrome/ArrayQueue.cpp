// Mateo Sanchez Sinche, CS 110C

#include "ArrayQueue.h"
#include "PrecondViolatedExcep.h"

ArrayQueue::ArrayQueue() : front(0), back(0)
{
}

bool ArrayQueue::isEmpty() const
{
    return front == back;
}

bool ArrayQueue::enqueue(const char& newEntry)
{
    if (front == (back + 1) % (MAX_QUEUE + 1))
        throw PrecondViolatedExcep("enqueue() called with full queue");

    back = (back + 1) % (MAX_QUEUE + 1);
    items[back] = newEntry;
    return true;
}

bool ArrayQueue::dequeue()
{
    if (isEmpty())
        return false;

    front = (front + 1) % (MAX_QUEUE + 1);
    return true;
}

char ArrayQueue::peekFront() const
{
    if (isEmpty())
		throw PrecondViolatedExcep("peekFront() called with empty queue");

    return items[(front + 1) % (MAX_QUEUE + 1)];
}