#include <iostream>
#include "Queue.h"

using namespace std;

// Constructor
Queue::Queue() {
    front = 0;
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

// Insert an element
void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert " << value << endl;
        return;
    }

    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = value;
    count++;

    cout << value << " inserted successfully." << endl;
}

// Remove an element
void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot remove element." << endl;
        return;
    }

    cout << arr[front] << " removed successfully." << endl;

    front = (front + 1) % MAX_SIZE;
    count--;
}

// View the front element
void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Front element: " << arr[front] << endl;
}

// Display all elements
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";

    for (int i = 0; i < count; i++) {
        cout << arr[(front + i) % MAX_SIZE] << " ";
    }

    cout << endl;
}