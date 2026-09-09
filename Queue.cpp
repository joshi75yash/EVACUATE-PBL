#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = -1;
    rear = -1;
}

bool Queue::isEmpty() {
    return front == -1;
}

void Queue::enqueue(int value) {
    if (rear == 49) {
        cout << "Queue is full\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    arr[rear] = value;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }

    int value = arr[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }

    return value;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";

    cout << endl;
}
