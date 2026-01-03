#include<bits/stdc++.h>
using namespace std;

// trapping rain water

//through prefixMax  and suffixmax apporach

int water(vector<int>&arr){
    int n = arr.size();
    vector<int>prefixMax(n);
    prefixMax[0]=arr[0];
    for(int i =1;i<n;i++){
        prefixMax[i]= max(prefixMax[i-1],arr[i]);
    }
    vector<int>suffixMax(n);
    suffixMax[n-1]=arr[n-1];
    for(int i = n-2;i>=0;i--){
        suffixMax[i]= max(suffixMax[i+1],arr[i]);
    }

    int ttlWater = 0;
    for(int i =0;i<n;i++){
        ttlWater += min(prefixMax[i],suffixMax[i]) - arr[i];
    }
    return ttlWater;
}

// without prefixMax
int water2(vector<int>&arr){
    int n = arr.size();
    vector<int>suffixMax(n);
    suffixMax[n-1]=arr[n-1];
    for(int i = n-2;i>=0;i--){
        suffixMax[i]= max(suffixMax[i+1],arr[i]);
    }

    int ttlWater = 0;
    int prefixMax = arr[0];
    for(int i =0;i<n;i++){
        prefixMax = max(prefixMax,arr[i]);
        ttlWater += min(prefixMax,suffixMax[i]) - arr[i];
    }
    return ttlWater;
}
