```cpp
#include "Queue.h"
#include <iostream>
using namespace std;

// Constructor
Queue::Queue() {
    front = -1;
    rear = -1;
    count = 0;
}

// Check whether queue is empty
bool Queue::isEmpty() {
    return count == 0;
}

// Check whether queue is full
bool Queue::isFull() {
    return count == MAX_SIZE;
}

// Add an element to the queue
void Queue::enqueue(int value) {

    if (isFull()) {
        cout << "Queue is full. Cannot insert " << value << ".\n";
        return;
    }

    // First element
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        // Circular movement
        rear = (rear + 1) % MAX_SIZE;
    }

    arr[rear] = value;
    count++;

    cout << value << " inserted into the queue.\n";
}

// Remove an element from the queue
int Queue::dequeue() {

    if (isEmpty()) {
        cout << "Queue is empty. Nothing to delete.\n";
        return -1;
    }

    int value = arr[front];

    // If this is the last element
    if (count == 1) {
        front = -1;
        rear = -1;
    }
    else {
        // Circular movement
        front = (front + 1) % MAX_SIZE;
    }

    count--;

    cout << value << " removed from the queue.\n";

    return value;
}

// Return the first element
int Queue::peek() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    return arr[front];
}

// Return the last element
int Queue::getRear() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    return arr[rear];
}

// Return number of elements
int Queue::size() {
    return count;
}

// Remove all elements
void Queue::clear() {

    front = -1;
    rear = -1;
    count = 0;

    cout << "Queue has been cleared.\n";
}

// Display all elements
void Queue::display() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements: ";

    int index = front;

    for (int i = 0; i < count; i++) {
        cout << arr[index] << " ";
        index = (index + 1) % MAX_SIZE;
    }

    cout << endl;
}

// Display front and rear information
void Queue::displayStatus() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front element : " << arr[front] << endl;
    cout << "Rear element  : " << arr[rear] << endl;
    cout << "Queue size    : " << count << endl;
    cout << "Free spaces   : " << MAX_SIZE - count << endl;
}
```

### You will also need to modify `Queue.h`

```cpp
#ifndef QUEUE_H
#define QUEUE_H

class Queue {

private:
    static const int MAX_SIZE = 50;

    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue();

    bool isEmpty();
    bool isFull();

    void enqueue(int value);
    int dequeue();

    int peek();
    int getRear();

    int size();

    void clear();
    void display();
    void displayStatus();
};



So when `rear` reaches the end, it can **come back to the beginning** and reuse empty spaces.

**This is a much better Data Structures implementation to understand because it introduces an important concept: Circular Queue.**
