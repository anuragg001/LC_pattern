#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfallSubarr(vector<int>&arr,int k){
    int n = arr.size();
    deque<int>dq;
    vector<int>res;
    int i=0,j=0;

    while(j<n){
        //calculation
        while(!dq.empty() && dq.back()<arr[j]){
            dq.pop_back();
        }
        dq.push_back(arr[j]);
        //window size not reached

        if(j-i+1<k){
            j++;
        }
        //window Size reached
        else if(j-i+1==k){
            res.push_back(dq.front());
            //remoove element i.e i
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