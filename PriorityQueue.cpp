#include "PriorityQueue.h"
#include <iostream>
#include <algorithm>
using namespace std;

PriorityQueue::PriorityQueue() : size(0) {}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

bool PriorityQueue::isFull() const {
    return size == CAPACITY;
}

int PriorityQueue::getSize() const {
    return size;
}

int PriorityQueue::peek() const {
    if (isEmpty()) {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    return heap[0];
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

void PriorityQueue::heapifyDown(int index) {
    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(heap[index], heap[smallest]);
        index = smallest;
    }
}

bool PriorityQueue::insert(int value) {
    if (isFull())
        return false;

    heap[size] = value;
    heapifyUp(size);
    size++;

    return true;
}

int PriorityQueue::remove() {
    if (isEmpty()) {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    int value = heap[0];

    heap[0] = heap[size - 1];
    size--;

    if (!isEmpty())
        heapifyDown(0);

    return value;
}

void PriorityQueue::display() const {
    if (isEmpty()) {
        cout << "Priority Queue is empty\n";
        return;
    }

    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";

    cout << '\n';
}
