#include<bits/stdc++.h>
using namespace std;

//Count the number of Good Pairs
const int M  = 1e9+7;
int pairs(vector<int>arr){
    int n = arr.size();
    unordered_map<int,int>mpp;
    for(int i =0;i<n;i++){
        mpp[arr[i]] = i;
    }
    int i =0;
    int j = 0;
    j = max(j, mpp[arr[0]]);
    int res = 1;
    while(i<n){
        if(i>j){
            res = (res*2)%M;
        }
        j = max(j, mpp[arr[i]]);
        i++;
    }
    return res;
}