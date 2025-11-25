#include<bits/stdc++.h>
using namespace std;
//dynamic programming approach to find minimum number of coins for all denominations

// through memoization 
vector<vector<int>>dp;
int solve(int idx,int amount,vector<int>&coins){
 if(amount==0)return 0;
 if(idx==coins.size())return 1e9;
 if(dp[idx][amount]!=-1)return dp[idx][amount];
    int npick = solve(idx+1,amount,coins);
    int pick =1e9;
    if(coins[idx]<=amount){
        pick = 1+solve(idx,amount-coins[idx],coins);
    }
    return dp[idx][amount]= min(pick ,npick);

}

int main(){
    vector<int>coins={1,3,4};
    int amount;
    cin>>amount;
    int n = coins.size();
    dp.resize(n+1,vector<int>(amount+1,-1));
    cout<<solve(0,amount,coins);

}