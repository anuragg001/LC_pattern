#include<bits/stdc++.h>
using namespace std;
//recursion +memoization approach for longest common subsequence
vector<vector<int>>dp;
int solve(int i,int j,string&s1,string&s2 ){
    if(i==s1.length() || j==s2.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve(i+1,j+1,s1,s2);
    }
    return dp[i][j]=max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));


}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    dp.resize(n+1,vector<int>(m+1,-1));
    cout<<solve(0,0,s1,s2);

}