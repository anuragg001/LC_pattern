#include<bits/stdc++.h>
using namespace std;

int longest(vector<int>&arr,int k){
    int n  = arr.size();
    unordered_map<int,int>mpp;
    long long sum =0;
    int maxlen =0;
    for(int i =0;i<n;i++){
        sum +=arr[i];
        if(sum==k){
            maxlen = i+1;
        }
        int rem = sum -k;
        if(mpp.find(rem)!=mpp.end()){
            int len = i-mpp[rem];
            maxlen = max(maxlen,len);
        }
        //for handling 0 
        if(mpp.find(sum)==mpp.end() ){
            mpp[sum]=i;
        }
    }
    return maxlen;
}



//let solve this using tow pointer and sliding window
int longest2(vector<int>&arr,int k){
    int n  = arr.size();
    int i=0;
    int j =0;
    int sum = 0;
    int maxlen =0;
    while(j<n){
        sum +=arr[j];
        while(left<=right && sum>k){
            sum -=arr[i];
            i++;
        }
        if(sum==k){
            maxlen = max(maxlen,j-i+1);
        }
        j++;
    }
    return maxlen;
}

int main(){
    vector<int>arr = {10,0,0,9};
    int k = 9;
    cout<<longest2(arr,k);
    return 0;
}