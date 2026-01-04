#include<bits/stdc++.h>
using namespace std;

//longest subarr with sum <=k

// 1. Generate all the subarr (BruteForce)
int generateSub(vector<int>&arr,int k ,int n ){
    int maxLen= 0;
    for(int i =0;i<n-1;i++){
        int sum = 0;
        for(int j =i;j<n-1;j++){
            sum +=arr[j];
            if(sum<=k)maxLen = max(maxLen,j-i+1);
            else if(sum>k) break;
        }
    }
    return maxLen;
}


// 2. Better/Optimal (Two Pointer) (Expand & shrink)
int longestFun(vector<int>&arr,int k,int n ){
    int sum =0;
    int l =0 , r=0;
    int maxlen=0;

    while(r<n){
        sum +=arr[r];
        while(sum>k){  // you can only put if condition to further optimized
            sum = sum -arr[l];
            l=l+1;
        }

        if(sum<=k)maxlen= max(maxlen,r-l+1);
        r=r+1;
    }
    return maxlen;
}


pair<int,int> longestFun2(vector<int>&arr,int k,int n ){
    int sum =0;
    int l =0 , r=0;
    int maxlen=0;
    pair<int,int>pt={-1,-1};

    while(r<n){
        sum +=arr[r];
        while(sum>k && l<=r){  // you can only put if condition to further optimized
            sum = sum -arr[l];
            l=l+1;
        }
        int len = r-l+1;
        if(sum<=k && len>maxlen){
            
            maxlen= len;
        pt={l,r};
        }
        r=r+1;
    }
    return pt;
}

int main(){
    vector<int>arr = {2,5,1,10,10};
    int n = 5;
    int k =14;
    pair<int,int> res = longestFun2(arr,k,n);
    cout<<res.first<<" " <<res.second;

    
}