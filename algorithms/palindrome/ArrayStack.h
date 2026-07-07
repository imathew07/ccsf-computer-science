// Mateo Sanchez Sinche, CS 110C

#ifndef _STACK_H_
#define _STACK_H_

const int MAX_STACK = 20;

class ArrayStack
{
private:
    char arr[MAX_STACK];
    int top;

public:
    ArrayStack();   // Default constructor

    bool isEmpty() const;
    bool push(const char& newEntry);
    bool pop();
    char peek() const;
};

#endif