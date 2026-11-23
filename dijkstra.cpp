    
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int>> graph[100];
int vis[100] = {0};

// DFS FUNCTION
void dfs(int u)
{
    cout << u << " ";
    vis[u] = 1;

    for(auto e : graph[u])
    {
        int v = e.first;

        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    int n, m;

    cout << "====================================\n";
    cout << "       EVACUATE - GRAPH DEMO\n";
    cout << "====================================\n";

    cout << "\nEnter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEnter edges as: source destination weight\n";

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    // DFS TRAVERSAL

    cout << "\n====================================\n";
    cout << "          DFS TRAVERSAL\n";
    cout << "====================================\n";

    int start;

    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    dfs(start);

    cout << "\n\nDFS completed successfully!\n";

    // RESET VISITED ARRAY

    for(int i=0; i<n; i++)
        vis[i] = 0;

    // DIJKSTRA ALGORITHM

    cout << "\n====================================\n";
    cout << "       DIJKSTRA SHORTEST PATH\n";
    cout << "====================================\n";

    int s, destination;

    cout << "Enter source vertex: ";
    cin >> s;

    cout << "Enter destination vertex: ";
    cin >> destination;

    int dist[100], parent[100];

    for(int i=0; i<n; i++)
    {
        dist[i] = 9999;
        parent[i] = -1;
    }

    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d != dist[u])
            continue;

        for(auto e : graph[u])
        {
            int v = e.first;
            int w = e.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v],v});
            }
        }
    }

    // DISPLAY RESULT

    cout << "\n====================================\n";
    cout << "             RESULT\n";
    cout << "====================================\n";

    if(dist[destination] == 9999)
    {
        cout << "No path exists to destination.\n";
    }
    else
    {
        vector<int> path;

        for(int v=destination; v!=-1; v=parent[v])
            path.push_back(v);

        reverse(path.begin(),path.end());

        cout << "Shortest Path: ";

        for(int i=0; i<path.size(); i++)
        {
            cout << path[i];

            if(i != path.size()-1)
                cout << " -> ";
        }

        cout << "\nTotal Path Cost: " << dist[destination];
        cout << "\n\nShortest path calculated successfully!\n";
    }

    cout << "\n====================================\n";
    cout << "          EVACUATE ENDED\n";
    cout << "====================================\n";

    return 0;
}
