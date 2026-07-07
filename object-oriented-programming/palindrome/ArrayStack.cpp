// Mateo Sanchez Sinche, CS 110C

#include "ArrayStack.h"
#include "PrecondViolatedExcep.h"

// Constructor to initialize the stack
ArrayStack::ArrayStack() : top(-1)
{
}

bool ArrayStack::isEmpty() const
{
    return top < 0;
}

bool ArrayStack::push(const char& newEntry)
{
    bool result = false;
    if (top < MAX_STACK - 1)
    {
        top++;
        arr[top] = newEntry;
        result = true;
    }
    return result;
}
bool ArrayStack::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }
    return result;
}

char ArrayStack::peek() const
{
    if (isEmpty())
		throw PrecondViolatedExcep("peek() called with empty stack");
    return arr[top];
}