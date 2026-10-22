#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;

    cout << "===== EVACUATE - DIJKSTRA DEMO =====\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of vertices.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter number of edges: ";
    cin >> m;

    if (m < 0)
    {
        cout << "Invalid number of edges.\n";
        return 0;
    }

    cout << "\nEnter each edge as: source destination weight\n";
    cout << "Vertices must be numbered from 0 to " << n - 1 << ".\n";
    cout << "Weights must be non-negative.\n";

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w < 0)
        {
            cout << "Invalid edge. Enter the graph again.\n";
            return 0;
        }

        // Undirected graph
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source, destination;

    cout << "\nEnter starting vertex: ";
    cin >> source;

    cout << "Enter destination vertex: ";
    cin >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n)
    {
        cout << "Invalid source or destination.\n";
        return 0;
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    // Min-priority queue stores {distance, vertex}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDistance != dist[u])
            continue;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (currentDistance <= INT_MAX - weight &&
                currentDistance + weight < dist[v])
            {
                dist[v] = currentDistance + weight;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    if (dist[destination] == INT_MAX)
    {
        cout << "\nNo path exists to the destination.\n";
        return 0;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\n===== RESULT =====\n";
    cout << "Shortest path: ";

    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i];

        if (i != (int)path.size() - 1)
            cout << " -> ";
    }

    cout << "\nTotal path cost: " << dist[destination] << endl;

    return 0;
}
