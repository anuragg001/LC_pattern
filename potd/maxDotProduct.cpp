#include<bits/stdc++.h>
using namespace std;

/*
 Max dot product of subsequence
 Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
*/


//through recursion and memoization

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j ,vector<int>&arr1,vector<int>&arr2){
        if(i==arr1.size()){
            if(j==0){
                return -1e9;
            }
            return 0;
        }
        if(j==arr2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        int nPick = solve(i+1,j,arr1,arr2);
        int pick = -1e9;
        for(int k =j;k<arr2.size();j++){
            pick = max(pick, arr1[i]*arr2[k]+solve(i+1,k+1,arr1,arr2));
        }
        return dp[i][j]=max(pick,nPick);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,nums1,nums2);
    }
};