#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
using namespace std;

class Route {
private:
    vector<int> path;

public:
    void addNode(int node);
    void display();
};

#endif
