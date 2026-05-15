#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dist(V, INT_MAX);

    // Min Heap -> {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int weight = it.second;

            // Relaxation
            if (d + weight < dist[adjNode])
            {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Shortest distances from source node " << src << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    // {node, weight}

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});

    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});

    adj[2].push_back({0, 4});
    adj[2].push_back({1, 1});
    adj[2].push_back({4, 3});

    adj[3].push_back({1, 7});
    adj[3].push_back({4, 1});

    adj[4].push_back({2, 3});
    adj[4].push_back({3, 1});

    int source = 0;

    dijkstra(V, adj, source);

    return 0;
}