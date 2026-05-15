#include<bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

void prims(int v,vector<vector<pii>> &adj){
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    vector<bool>vis(v,false);
    pq.push({0,{0,-1}});
    int cost=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        if(parent!=-1){
            cout<<"edge "<<node<<" - "<<parent<<endl;
        }
        cost+=wt;
        for(auto it:adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;
            if(!vis[adjnode]){
                pq.push({adjwt,{adjnode,node}});
            }
        }
    }
    cout<<cost<<endl;
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