#include<bits/stdc++.h>
using namespace std;

//minimum size subarray sum

int minimum(vector<int>&arr,int k){
    int n= arr.size();
    int i=0,j=0;
    int sum =0;
    int ans = INT_MAX;
    while(j<n){
        sum+=arr[j];

        while(sum>=k){
            ans = min(ans,j-i+1);
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return ans==INT_MAX?-1:ans;
}