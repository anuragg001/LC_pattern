#include<bits/stdc++.h>
using namespace std;

/*
    cycle detection in a directed graph using DFS
    using though two flags:visited[] and dfsVisited[]

    the difference between undirected ans directed cycle detection is that in undirected graph we need to keep track of parent node to avoid false positive cycel detection whereas ,
     based  on current recursion stack  
*/

bool isCycleDFS( unordered_map<int,vector<int>>&adj, int u ,vector<bool>& visited , vector<bool>& inRecursion){

    visited[u] = true;
    inRecursion[u]= true;

    for(auto &v:adj[u]){
        if(!visited[v]  && isCycleDFS(adj,v,visited,inRecursion)){
            return true;
        }
        else if(inRecursion[v]){
            return true;
        }
    }
    inRecursion[u] = false;
    return false;
}


bool isCyclic(int V , vector<vector<int>>&edges){

    unordered_map<int,vector<int>>adj;

    for(auto &vec:edges){
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
    }

    vector<bool> visited(V,false);
    vector<bool> inRecursion(V,false);

    for(int i =0;i<V;i++){
        if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)){
            return true;
        }
    }
    return false;

}
