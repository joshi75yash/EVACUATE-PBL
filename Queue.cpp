#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        count++;

        cout << value << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << arr[front] << " removed\n";
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX_SIZE] << " ";
        }

        cout << endl;
    }
};
