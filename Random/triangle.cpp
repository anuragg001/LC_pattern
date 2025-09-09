#include<bits/stdc++.h>
using namespace std;

//memoized
vector<vector<int>>dp;
int solve(vector<vector<int>>&tri,int i,int j){
    int n = tri.size();
    if(i==n-1)return tri[i][j];
    if(dp[i][j]!=1e9)return dp[i][j];
    int fs = tri[i][j]+solve(tri,i+1,j);
    int ss= tri[i][j]+solve(tri,i+1,j+1);
    return dp[i][j]= min(fs,ss);
}


int main(){
    vector<vector<int>> tri={{2},{3,4},{6,5,7},{4,1,8,3}};
    int n = tri.size();
    dp.resize(n,vector<int>(n,1e9));
    cout<<solve(tri,0,0)<<endl;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//op-> 11
//Time Complexity: O(n^2)
//space Complexity: O(n^2) + O(n) for recursion stack space