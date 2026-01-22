#include<bits/stdc++.h>
using namespace std;


//Number of Provinces

void dfs(unordered_map<int,vector<int>>&adj,int u , vector<bool>&visited){
    visited[u]=true;

    for(int &v:adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}

int Provinces(vector<vector<int>>&isConnected){
    int n = isConnected.size();

    //making the graph 
    unordered_map<int,vector<int>>adj;
    for(int u = 0;u<n;u++){
        for(int v = 0;v<n;v++){
            if(isConnected[u][v]==1){
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
        }
    }
    vector<bool>visited(n,false);
    int cnt = 0;

    //dfs call
    for(int i =0;i<n;i++){
        if(!visited[i]){
            dfs(adj,i,visited);
            cnt++;
        }
    }
    return cnt;
}