#include<bits/stdc++.h>
using namespace std;

int majority(vector<int>&arr){
    int n = arr.size();
    unordered_map<int,int>mpp;
    for(int i =0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/2){
            return it.first;
        }
    }
    return -1;
}


int main(){
    vector<int>arr = {10,0,0,9,0};
    int k = 9;
    cout<<majority(arr);
    return 0;
}