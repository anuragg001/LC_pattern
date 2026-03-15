#include<bits/stdc++.h>
using namespace std;

// Dijkstra algorithm thorugh priority queue

// representation of the graph  thorugh adjacency list 
vector<int> dijkstra(int V, vector<vector<int>>adj[],int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>dist(V,INT_MAX);
    dist[source] = 0;
    pq.push({0,source}); //{distance,node}

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto &vec:adj[u]){
            int v = vec[0];
            int wt = vec[1];

            if(d+wt< dist[v]){
                dist[v] = d+wt;
                pq.push({d+wt,v});
            }
        }
    }
    return dist;
}

    