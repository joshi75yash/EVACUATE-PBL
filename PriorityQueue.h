#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue
{
private:
    static const int CAPACITY = 50;
    int heap[CAPACITY];
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue();

    bool insert(int value);
    int remove();

    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;

    void display() const;
};

#endif
