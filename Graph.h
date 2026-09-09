#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v);
    void addEdge(int u, int v);
    void display();
    void BFS(int start);
};

#endif
