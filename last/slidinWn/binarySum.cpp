#include<bits/stdc++.h>
using namespace std;

//ps -> binary subarry with sum equal to k


int sum (vector<int>&arr,int k){
    int n = arr.size();
    int i=0,j=0;
    int currsum=0;
    int ans=0;
    while(j<n){
        currsum+=arr[j];
        while(currsum>k){
            currsum-=arr[i];
            i++;
        }
        if(currsum==k){
            ans++;
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int>arr={1,0,1,0,1};
    int k=2;
    cout<<sum(arr,k);
    // Expected output: 4
}