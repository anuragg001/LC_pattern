#include<bits/stdc++.h>
using namespace std;

//Number of operation to make ntwrk connected
vector<int>parent;
vector<int>rank;
int find(int i){
    if(i==parent[i])return i;
    return parent[i]= find(parent[i]);
}
void Union(int x ,int y){
    int xParent = find(x);
    int yParent = find(y);

    if(xParent == yParent)return;

    if(rank[xParent]>rank[yParent]){
        parent[yParent] = xParent;
    }else if(rank[xParent]<rank[yParent]){
        parent[xParent] = yParent;
    }else{
        parent[yParent]= xParent;
        rank[xParent] +=1;
    }
}



int makeconnected( int n ,vector<vector<int>>&conn){
    
}