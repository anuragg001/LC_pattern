#include<bits/stdc++.h>
using namespace std;

// sliding window maximum 
//thorugh dequeue optimal approach 

vector<int> sliding(vector<int>&arr,int k){
    int n = arr.size();
    deque<int>dq;
    vector<int>ans;

    for(int i =0;i<n;i++){

        //remove element which are out of current window
        if(!dq.empty() && dq.front()== i-k){
            dq.pop_front();  //removal from front 
        }

        //remoove all element smaller than current element from back
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back(); //removal from back
        }

        dq.push_back(i); //insertion at baack;

        //start adding to ans whe we have first window
        if(i>=k-1){
            ans.push_back(arr[dq.front()]); //front of dequeue is always maximum 
        }

    }
    return ans;
}