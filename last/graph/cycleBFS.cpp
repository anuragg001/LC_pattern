#include<bits/stdc++.h>
using namespace std;

/*
    cycle detection in an undirected graph using BFS
    using though two flags:visited[] and parent
*/


bool cycleBFS(unordered_map<int,vector<int>>&adj,int u ,vector<bool>&visited,int parent){
    queue<pair<int,int>>q; //{node,parent}

    q.push({u,parent});
    visited[u]=true;

    while(!q.empty()){
        pair<int,int>p = q.front();q.pop();

        int u = p.first;
        int parent = p.second;

        for(int &v:adj[u]){
            if(!visited[v]){
                q.push({v,u});
                visited[v]=true;
            }else if(visited[v] && v!=parent){   // no need to chcek visited[v]==true because we are in else block
                return true; //cycle detected
            }

        }


    }
    return false;
}


bool isCycle(int V,vector<vector<int>>&graph){
    unordered_map<int,vector<int>>adj;

    for(auto &vec:graph){
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(V,false);

    for(int i =0;i<V;i++){
        if(!visited[i] && cycleBFS(adj,i,visited,-1))return true;
    }
    return false;
}