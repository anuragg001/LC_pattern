#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int solve( int idx,int W,vector<int>&wt,vector<int>&val,int n){
    if(idx==val.size() || W==0){
        return 0;
    }
    if(dp[idx][W]!=-1){
        return dp[idx][W];
    }
    if(wt[idx]>W)
    return dp[idx][W] = solve(idx+1,W,wt,val,n);

    int npick = solve(idx+1,W,wt,val,n);
    int pick = val[idx]+solve(idx+1,W-wt[idx],wt,val,n);
    return dp[idx][W] = max(pick, npick);
}

int main(){
    vector<int>weight={10,20,30};
    vector<int>value={60,100,120};
    int W=50;
    int n=weight.size();
    dp.resize(n+1,vector<int>(W+1,-1)); 
    cout<<solve(0,W,weight,value,n);
    return 0;
}