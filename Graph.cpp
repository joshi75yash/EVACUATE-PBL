#include "Graph.h"

Graph::Graph(int v) {
    vertices = v;
    adj.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::display() {
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";

        for (int node : adj[i]) {
            cout << node << " ";
        }

        cout << endl;
    }
}

void Graph::BFS(int start) {
    vector<bool> visited(vertices, false);
    vector<int> queue;

    queue.push_back(start);
    visited[start] = true;

    int index = 0;

    while (index < queue.size()) {
        int current = queue[index++];
        cout << current << " ";

        for (int node : adj[current]) {
            if (!visited[node]) {
                visited[node] = true;
                queue.push_back(node);
            }
        }
    }

    cout << endl;
}
