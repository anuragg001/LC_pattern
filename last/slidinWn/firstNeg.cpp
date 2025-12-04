#include<bits/stdc++.h>
using namespace std;

vector<int> firstNeg(vector<int>&arr,int n,int k){
    deque<int>dq;
    vector<int>res;
    int i =0,j=0;
    while(j<n){
        if(arr[j]<0){
            dq.push_back(j);
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(dq.size()==0){
                res.push_back(0);   
            }else{
                res.push_back(arr[dq.front()]);
                if(dq.front()==i){
                    dq.pop_front();
                }
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
    // Expected output: -1 -7 -15
}