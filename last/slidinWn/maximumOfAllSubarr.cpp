#include<bits/stdc++.h>
using namespace std;

//the pronnlem statement is -> Given an array of integers arr and an integer k, 
// find the maximum element of all subarrays of size k.

/*
    the reason why to use deque is
    1. we can push and pop from both ends in O(1) time
    2. we can maintain the decreasing order of elements in the deque
    3. the front of the deque always contains the maximum element of the current window




*/

vector<int> maxOfallSubarr(vector<int>&arr,int k){
    int n = arr.size();
    int i =0,j=0;
    deque<int>dq;
    vector<int>res;
    while(j<n){
        while(!dq.empty() && dq.front()<arr[j]){
            dq.pop_front();
        }
        dq.push_back(arr[j]);

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            res.push_back(dq.front());
            if(dq.front()==arr[i]){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}



int main(){
    vector<int>arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>ans=maxOfallSubarr(arr,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    //output:3 3 5 5 6 7
}