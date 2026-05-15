#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
void dijkstra(int v,vector<vector<pair<int, int>>> &adj,int src){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(v,1e9);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;
            if(wt+adjwt<dist[adjnode]){
                dist[adjnode]=wt+adjwt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    for(auto it:dist) cout<<it<<" ";
    cout<<endl;
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