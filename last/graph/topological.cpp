#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj ,int u , vector<bool>& visited, stack<int>&st ){
    visited[u] = true;

    for(auto &v:adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited,st);
        }
    }
    st.push(u);

}

vector<int> topp(int V , vector<vector<int>>&edges){

    unordered_map<int,vector<int>>adj;

    for(auto &vec:edges){
        int u = vec[0];
        int v = vec[1];

        adj[u].push_back(v);
    }

    vector<bool>visited(V,false);
    stack<int>st;

    for(int i =0;i<V;i++){
        if(!visited[i]){
            dfs(adj,i,visited,st);
        }
    }

    vector<int>res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
