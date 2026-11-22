#include <iostream>
#include <cassert>
#include <sstream>
#include <functional>
#include "Queue.h"

using namespace std;

string captureOutput(function<void()> action) {
    ostringstream output;
    streambuf* oldBuffer = cout.rdbuf(output.rdbuf());

    action();

    cout.rdbuf(oldBuffer);
    return output.str();
}

int main() {
    Queue q;

    // Test 1: Empty Queue
    assert(q.isEmpty());
    cout << "Test 1 Passed: Empty Queue\n";

    // Test 2: Insertion
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    assert(!q.isEmpty());
    cout << "Test 2 Passed: Insertion\n";

    // Test 3: FIFO
    assert(captureOutput([&]() {
        q.dequeue();
    }) == "10 removed successfully.\n");

    cout << "Test 3 Passed: FIFO Order\n";

    // Test 4: Circular insertion
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    assert(q.isFull());

    cout << "Test 4 Passed: Circular Insertion\n";

    // Test 5: Overflow
    assert(captureOutput([&]() {
        q.enqueue(70);
    }) == "Queue is full! Cannot insert 70\n");

    cout << "Test 5 Passed: Overflow Handling\n";

    // Test 6: Front element
    assert(captureOutput([&]() {
        q.peek();
    }) == "Front element: 20\n");

    cout << "Test 6 Passed: Peek Operation\n";

    // Test 7: Display
    assert(captureOutput([&]() {
        q.display();
    }) == "Queue elements: 20 30 40 50 60 \n");

    cout << "Test 7 Passed: Display\n";

    // Test 8: Empty the Queue
    for (int i = 0; i < 5; i++) {
        q.dequeue();
    }

    assert(q.isEmpty());

    cout << "Test 8 Passed: Complete Deletion\n";

    // Test 9: Underflow
    assert(captureOutput([&]() {
        q.dequeue();
    }) == "Queue is empty! Cannot remove element.\n");

    cout << "Test 9 Passed: Underflow Handling\n";

    cout << "\nAll Queue Tests Passed Successfully!\n";

    return 0;
}
