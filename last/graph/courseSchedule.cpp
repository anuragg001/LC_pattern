#include<bits/stdc++.h>
using namespace std;


//course schedule probem 
/*
 The intuion will be that well use topological sort to detect cycle in directed graph
 if there is a cycle then we cant complete all the courses otherwise we can 
*/

bool topo(unordered_map<int,vector<int>>&adj , int V , vector<int>&indegree){

    queue<int>q;
    int cnt = 0;

    //push all the edges with indegree 0
    for(int i =0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
            cnt++;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v:adj[u]){
            indegree[v]--;
            
            if(indegree[v]==0){
                q.push(v);
                cnt++;
            }
        }


    }
    return cnt==V;
}



bool canFinish(int nuCourses, vector<vector<int>>& preq){
    unordered_map<int,vector<int>>adj;
    vector<int>indegree(nuCourses,0);
    for(auto &vec:preq){
        int u = vec[0];
        int v =vec[1];

        //b->a means a is preq of b
        adj[v].push_back(u);

        //increase indegree of a
        indegree[u]++;
    }

    return topo(adj,nuCourses,indegree);

}