#include<bits/stdc++.h>
using namespace std;

//the problem statement is -> Given an array of integers arr and an integer k,
// find the first negative integer in every window of size k. If a window does not contain
//return 0 for that window.

vector<int> firstNeg(vector<int>&arr,int n,int k){
    int i =0,j=0;
    vector<int>res;
    deque<int>dq;
    while(j<n){
        if(arr[j]<0){
            dq.push_back(arr[j]);
        }
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
    vector<int>arr={12,-1,-7,8,-15,30,16,28};   
    int k=3;
    vector<int>ans=firstNeg(arr,arr.size(),k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    // Expected output: 
}