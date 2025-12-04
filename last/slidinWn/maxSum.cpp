#include<bits/stdc++.h>
using namespace std;


int maxSum(vector<int>&arr,int n,int k){
    int i=0,j=0;
    int currsum =0,maxsum =0;

    while(j<n){
        currsum +=arr[j];
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            maxsum = max(maxsum,currsum);
            currsum -=arr[i];
            i++;
            j++;
        }
    }
    return maxsum;
}



int main(){
vector<int>arr={2,1,5,1,3,2};
int k=3;
cout<<maxSum(arr,arr.size(),k);

}