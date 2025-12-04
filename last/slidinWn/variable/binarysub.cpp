#include<bits/stdc++.h>
using namespace std;
//ps-> binary subarray whoose sum is k 
//return the number of subarry with sum k 
//we can solve this with sliding window bcos it have only binary number 
//sliding window
//we have to return the total nos of subarry with sum k 
int cntSubarr(vector<int>&arr,int k){
    int n = arr.size();
    int i =0,j=0;
    int sum =0;
    int ans =0;
    while(j<n){
        sum+=arr[j];
        while(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            ans+=j-i+1; // count this subarray from i to j
        }
        j++;
       
    }
    return ans;
    
}

int main(){
    vector<int>arr = {1,0,1,0,1};
    int k = 2;
    cout<<cntSubarr(arr,k)<<endl; // Output: 4
    return 0;
}