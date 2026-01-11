#include<bits/stdc++.h>
using namespace std;

//bfs traversal of grph

void bfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&res){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    res.push_back(u);

    while(!q.empty()){
        int u =  q.front();q.pop();
        
        for(int &v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
                res.push_back(v);
            }
        }
    }
}