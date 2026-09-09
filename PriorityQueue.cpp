#include "PriorityQueue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() {
    size = 0;
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

void PriorityQueue::heapifyUp(int index) {

    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(heap[parent], heap[index]);

        index = parent;
    }
}

void PriorityQueue::insert(int value) {

    if (size == 50) {
        cout << "Priority Queue is full\n";
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

int PriorityQueue::remove() {

    if (isEmpty()) {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    int value = heap[0];

    heap[0] = heap[size - 1];
    size--;

    return value;
}

void PriorityQueue::display() {

    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";

    cout << endl;
}
