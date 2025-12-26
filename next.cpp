#include<bits/stdc++.h>
using namespace std;

//ps -> Next greater element in array

//brute force O(n^2) approach

vector<int> nge(vector<int>&arr){
    vector<int>res;
    int n = arr.size();
    for(int i =0;i<n;i++){
        int next = -1;
        for(int j =i+1;j<n;j++){
            if(arr[j]>arr[i]){
                next = arr[j];
                break;
            }

        }
        res.push_back(next);
    }
    return res;
}
