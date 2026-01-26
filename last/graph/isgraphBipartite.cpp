#include<bits/stdc++.h>
using namespace std;


//is Graph Bipartite or not 
// by dfs 
bool dfs(vector<vector<int>>&adj, int u , vector<int>&color , int currColor){
    color[u]= currColor;

    for(int &v:adj[u]){
        if(color[u]==color[v])
        return false;

        if(color[v]==-1){
            if(!dfs(adj,v,color,1-currColor))
            return false;
        }
    }
    return true;
}

//by bfs method
bool bfs(vector<vector<int>>&adj ,int u , vector<int>&color, int currColor){
    queue<int>q;
    q.push(u);
    color[u]=currColor;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v:adj[u]){
            if(color[u]==color[v])
            return false;

            if(color[v]==-1){
                color[v]= 1 -currColor;
                q.push(v);
            }
        }
    }
    return true;
}


bool isbi(vector<vector<int>>&adj){
    int n = adj.size();

    vector<int>color(n,-1);


    for(int i =0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(adj,i,color,1))
            return false;
        }
    }
    return true;
}