#include "Route.h"
#include <iostream>

void Route::addNode(int node) {
    path.push_back(node);
}

void Route::display() const {
    if (path.empty()) {
        std::cout << "Route: [Empty]" << std::endl;
        return;
    }

    std::cout << "Route: ";
    for (std::size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> "; // Visual indicator for a path sequence
        }
    }
    std::cout << std::endl;
}

bool Route::isEmpty() const {
    return path.empty();
}

void Route::clear() {
    path.clear();
}

std::size_t Route::size() const {
    return path.size();
}
