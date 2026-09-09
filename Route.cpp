#include "Route.h"
#include <iostream>

void Route::addNode(int node) {
    path.push_back(node);
}

void Route::display() {
    cout << "Route: ";

    for (int node : path) {
        cout << node << " ";
    }

    cout << endl;
}
