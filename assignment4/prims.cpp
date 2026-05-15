#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void prims(int V, vector<vector<pii>> &adj) {

    // {weight, {node, parent}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    vector<bool> visited(V, false);

    pq.push({0, {0, -1}});

    int totalCost = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        totalCost += weight;

        // Skip first node because parent = -1
        if (parent != -1) {
            cout << parent << " - " << node
                 << " : " << weight << endl;
        }

        for (auto it : adj[node]) {

            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, {adjNode, node}});
            }
        }
    }

    cout << "\nTotal Cost of MST: " << totalCost;
}

int main() {

    int V = 5;

    vector<vector<pii>> adj(V);

    // u -- v , weight

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    prims(V, adj);

    return 0;
}