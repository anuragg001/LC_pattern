#include<bits/stdc++.h>
using namespace std;

//cycle detectetion in directed graph is aka kahn's algorithm 

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
        }
        
        queue<int>q;
        vector<int>indegree(V,0);
        
        //creating the indegree
       for(int u =0;u<V;u++){
           for(int &v:adj[u]){
               indegree[v]++;
           }
       }
        
        //push the element with indegree 0
        for(int i =0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //bfs;
        vector<int>res;
        while(!q.empty()){
            int u = q.front();
            res.push_back(u);
            q.pop();
            
            for(int &v:adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return res;
    }
};