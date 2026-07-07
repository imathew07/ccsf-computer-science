// Mateo Sanchez Sinche, CS 110C

#ifndef _STACK_H_
#define _STACK_H_

class ArrayStack
{
private:
    char arr[100];
    int top;

public:
    ArrayStack();   // Default constructor

    bool isEmpty() const;
    bool push(const char& newEntry);
    bool pop();
    char peek() const;
};

#endif