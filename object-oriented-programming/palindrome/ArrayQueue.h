// Mateo Sanchez Sinche, CS 110C

#ifndef _QUEUE_H_
#define _QUEUE_H_

const int MAX_QUEUE = 20;

class ArrayQueue
{
private:
	char items[MAX_QUEUE + 1]; // Array of queue items (one more than MAX_QUEUE to distinguish full vs empty) (Extra Credit)
	int front; // Index BEFORE the front of the queue
	int back;  // Index to the back of the queue

public:
    ArrayQueue();

    bool isEmpty() const;
    bool enqueue(const char& newEntry);
    bool dequeue();
    char peekFront() const;
};

#endif