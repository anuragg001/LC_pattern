#include<bits/stdc++.h>
using namespace std;

//write the brute force approach to find the maximum consecutive 1's in a binary array

int consecutive1(vector<int>&arr,int k){
    int maxlen =0;
    int n = arr.size();
    for(int i =0;i<n;i++){
        int zcnt =0;
        for(int j =i;j<n;j++){
            if(arr[j]=='0')zcnt++;
            if(zcnt>k)break;
            if(zcnt<=k){
                maxlen = max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}