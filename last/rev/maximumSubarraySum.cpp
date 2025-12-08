#include<bits/stdc++.h>
using namespace std;

//maximum subarray sum using kadanses algorithm

int maxSub(vector<int>&arr){
    int n =arr.size();
    int maxSum = INT_MIN;
    int currSum =0;
    for(int i =0;i<n;i++){
        currSum +=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }

        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}


int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSub(arr);
    return 0;
}