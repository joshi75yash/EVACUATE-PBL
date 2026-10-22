#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        // Check if vertices are valid
        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices) {
            cout << "Invalid vertex number!" << endl;
            return;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);

        cout << "Edge added successfully!" << endl;
    }

    void BFS(int start) {
        // Check starting vertex
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbour : adj[current]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
    }
};
