#include<bits/stdc++.h>
using namespace std;


//shuffle an array with using extra space
void shuffle(vector<int>&nums, int n){
    vector<int>res(2*n);
    for(int i =0;i<n;i++){
        res[2*i] = nums[i];
        res[2*i+1] = nums[i+n];
    }
    nums = res;
}