#include<bits/stdc++.h>
using namespace std;

//DFS Traversal of Graph

void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
    if(visited[u])return;
    visited[u]=true;
    cout<<u<<" ";
    for(int &v:adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}