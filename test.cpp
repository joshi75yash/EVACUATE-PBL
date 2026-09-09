#include <iostream>
#include "Graph.h"

using namespace std;

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Graph:" << endl;
    g.display();

    cout << "\nBFS starting from 0:" << endl;
    g.BFS(0);

    return 0;
}
