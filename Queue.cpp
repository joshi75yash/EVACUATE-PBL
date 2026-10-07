
#include "Queue.h"
#include <iostream>
using namespace std;


Queue::Queue() {
    front = -1;
    rear = -1;
    count = 0;
}


bool Queue::isEmpty() {
    return count == 0;
}


bool Queue::isFull() {
    return count == MAX_SIZE;
}


void Queue::enqueue(int value) {

    if (isFull()) {
        cout << "Queue is full. Cannot insert " << value << ".\n";
        return;
    }

    
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
       
        rear = (rear + 1) % MAX_SIZE;
    }

    arr[rear] = value;
    count++;

    cout << value << " inserted into the queue.\n";
}


int Queue::dequeue() {

    if (isEmpty()) {
        cout << "Queue is empty. Nothing to delete.\n";
        return -1;
    }

    int value = arr[front];

    
    if (count == 1) {
        front = -1;
        rear = -1;
    }
    else {
       
        front = (front + 1) % MAX_SIZE;
    }

    count--;

    cout << value << " removed from the queue.\n";

    return value;
}


int Queue::peek() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    return arr[front];
}


int Queue::getRear() {

    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    return arr[rear];
}

int Queue::size() {
    return count;
}


void Queue::clear() {

    front = -1;
    rear = -1;
    count = 0;

    cout << "Queue has been cleared.\n";
}

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

