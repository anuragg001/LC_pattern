#include<bits/stdc++.h>
using namespace std;

// Disjoint Set Union 

int find(int i , vector<int>&parent){
    if(i==parent[i])
    return i;

    return find(parent[i],parent);
}

void Union(int x ,int y , vector<int>&parent){
    int xParent = find(x,parent);
    int yParent = find(y,parent);

    if(xParent!=yParent){
        parent[xParent] = yParent;
    }
}

// Using Rank and path compression

int find2(int i , vector<int>&parent){
    if(i==parent[i])return i;
    return parent[i] = find(parent[i],parent);
}

void union2(int x ,int y , vector<int>&parent , vector<int>&rank){
    int xParent = find2(x,parent);
    int yParent = find2(y,parent);

    if(xParent==yParent)return;

    if(rank[xParent]>rank[yParent]){
        parent[yParent]= xParent;
    }else if(rank[xParent]<rank[yParent]){
        parent[xParent] = yParent;
    }else{
        parent[yParent]= xParent;
        rank[xParent] +=1;
    }

}