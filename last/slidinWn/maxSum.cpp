#include<bits/stdc++.h>
using namespace std;

//The problem statement-> Given an array of integers arr and an integer k,
// find the maximum sum of a subarray of size k.


int maxSum(vector<int>&arr,int n,int k){
    int i =0,j=0;
    int currSum =0,maxSum=0;
    while(j<n){
        currSum +=arr[j];
        if(j-i+1<k){
            j++;
        }
       else if(j-i+1==k){
            maxSum =max(maxSum,currSum);
            currSum-=arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}



int main(){
vector<int>arr={2,1,5,-7,3,2};
int k=3;
cout<<maxSum(arr,arr.size(),k);

}