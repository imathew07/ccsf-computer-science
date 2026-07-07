// Mateo Sanchez Sinche, CS 110C
// A C++ program to check if a string is a palindrome using a stack and a queue.

#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "PrecondViolatedExcep.h"

using namespace std;

bool isPalindrome(const string& S)
{
    ArrayStack stack;
    ArrayQueue queue;

    // Fill the stack and the queue
    for (char c : S)
    {
        stack.push(c);
        queue.enqueue(c);
    }

    // Check if the stack and queue can accommodate the character
    while (!stack.isEmpty() && !queue.isEmpty())
    {
        if (stack.peek() != queue.peekFront())
            return false;

        stack.pop();
        queue.dequeue();
    }

    return true;
}

int main()
{
    string test1 = "mom";
    string test2 = "dog";
    string test3 = "radar";
	string test4(21, 'a'); // A string of 21 'a' characters, which exceeds the stack and queue capacity

    cout << test1 << ": " << (isPalindrome(test1) ? "Palindrome" : "Not Palindrome") << "\n";
    cout << test2 << ": " << (isPalindrome(test2) ? "Palindrome" : "Not Palindrome") << "\n";
    cout << test3 << ": " << (isPalindrome(test3) ? "Palindrome" : "Not Palindrome") << "\n";

	// Test the case that exceeds the stack and queue capacity
    try
    {
        bool result = isPalindrome(test4);
        cout << test4 << ": " << (result ? "Palindrome" : "Not Palindrome") << "\n";
    }
    catch (const PrecondViolatedExcep& e)
    {
        cout << test4 << ": " << e.what() << "\n";
    }
	return 0;
}

/* SAMPLE OUTPUT:
mom: Palindrome
dog: Not Palindrome
radar: Palindrome
aaaaaaaaaaaaaaaaaaaaa: Precondition Violated Exception: enqueue() called with full queue
*/