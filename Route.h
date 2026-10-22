#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

class Route {
private:
    std::vector<int> path;

public:
    void addNode(int node);
    void display() const;
    bool isEmpty() const;
    void clear();
    std::size_t size() const;
};

#endif#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

class Route {
private:
    std::vector<int> path;

public:
    void addNode(int node);
    void display() const;
    bool isEmpty() const;
    void clear();
    std::size_t size() const;
};

#endif
