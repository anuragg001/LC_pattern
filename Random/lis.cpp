#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int solve(int idx,int prev, vector<int>&arr){
    if(idx==arr.size())return 0;
    if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
    int nottake = solve(idx+1,prev,arr);
    int take = 0;
    if(prev==-1 || arr[idx]>arr[prev]){
        take = 1 + solve(idx+1,idx,arr);
    }
    return dp[idx][prev+1] = max(take,nottake);
}

int main(){
    vector<int>arr={10,9,2,5,3,7,101,18};
    int n = arr.size();
    dp.resize(n,vector<int>(n+1,-1));
    cout << solve(0,-1,arr);
    return 0;
}