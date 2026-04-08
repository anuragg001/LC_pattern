#include<bits/stdc++.h>
using namespace std;

//Xor after Range multipllication query 1
const int M = 1e9 + 7;
int xorRange(vector<int>&arr , vector<vector<int>>&queries){
    
    for(auto &q:queries){
        int l = q[0];
        int r = q[1];
        int k = q[2];
        int v = q[3];
        while(l<=r){
            arr[l] = (1LL* arr[l] * v)%M;
            l += k;
        }
    }
    int res = 0;
    for(auto & num:arr){
        res ^= num;
    }
    return res;
}