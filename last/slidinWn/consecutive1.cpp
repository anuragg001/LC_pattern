#include<bits/stdc++.h>
using namespace std;

//write the brute force approach to find the maximum consecutive 1's in a binary array

int consecutive1(vector<int>&arr,int k){
    int maxlen =0;
    int n = arr.size();
    for(int i =0;i<n;i++){
        int zcnt =0;
        for(int j =i;j<n;j++){
            if(arr[j]==0)zcnt++;
            if(zcnt>k)break;
            if(zcnt<=k){
                maxlen = max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}

//the optimized approach to find the maximum consecutive 1's in a binary array
//through slding window technique

int consec1(vector<int>&arr,int k){
    int n = arr.size();
    int i =0,j=0;
    int zcnt =0;
    int maxlen=0;
    while(j<n){
        if(arr[j]==0){
            zcnt++;
        }
        while(zcnt>k){
            if(arr[i]==0){
                zcnt--;
            }
            i++;
        }
        maxlen=max(maxlen,j-i+1);
        j++;
    }
    return maxlen;
}

int main(){
    vector<int>arr={1,1,0,0,1,1,1,0,1,1,1,1};
    int k=2;
    cout<<consec1(arr,k);   
    // Expected output: 9
}