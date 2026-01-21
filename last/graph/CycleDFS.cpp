#include<bits/stdc++.h>
using namespace std;

/*
Cycle detection in an undirected graph using DFS
using thourgh two flags: visited[] and parent

*/

bool cycleDFS(unordered_map<int,vector<int>>&adj,int u ,vector<bool>&visited,int parent){
    visited[u]=true;

    for(int &v:adj[u]){
        if(v==parent)continue; //skip the parent node
        if(visited[v])return true; //cycle detected
        if(!visited[v]){
            if(cycleDFS(adj,v,visited,u))return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& graph) {
       unordered_map<int,vector<int>>adj;

       for(auto &vec:graph){
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
       }
         vector<bool>visited(V,false);  
         for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycleDFS(adj,i,visited,-1))return true;
            }
         }
            return false;
    }