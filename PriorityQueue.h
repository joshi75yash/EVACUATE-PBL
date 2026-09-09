#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class PriorityQueue {
private:
    int heap[50];
    int size;

    void heapifyUp(int index);

public:
    PriorityQueue();

    void insert(int value);
    int remove();
    bool isEmpty();
    void display();
};

#endif
