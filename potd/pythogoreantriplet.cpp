#include<bits/stdc++.h>
using namespace std;


/*
Pythogrenan Triplet
*/
vector<int>bfs(unordered_map<int,vector<int>>&adj , int n , int u){
    vector<int>dist(n,-1);
    queue<int>q;

    q.push(u);
    dist[u] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v:adj[u]){
            if(dist[v]==-1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }

    }
    return dist;
}

int special(int n , vector<vector<int>>&edges,int x ,int y , int z){
    unordered_map<int,vector<int>>adj;

    for(auto &vec:edges){
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dx = bfs(adj,n,x);
    vector<int>dy = bfs(adj,n,y);
    vector<int>dz = bfs(adj,n,z);

    int cnt = 0;
    for(int i =0;i<n;i++){
        vector<long long>d = {dx[i],dy[i],dz[i]};
        sort(d.begin(),d.end());

        if(d[0]*d[0] + d[1]*d[1] == d[2]*d[2]){
            cnt++;
        }
    }
    return cnt;
}