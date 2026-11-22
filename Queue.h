#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front, rear, count;

public:
    Queue();

    bool isEmpty();
    bool isFull();

    void enqueue(int value);
    void dequeue();
    void peek();
    void display();
};

#endif