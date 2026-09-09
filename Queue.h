#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int arr[50];
    int front;
    int rear;

public:
    Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty();
    void display();
};

#endif
