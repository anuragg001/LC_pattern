#include<bits/stdc++.h>
using namespace std;



int fun(vector<int>&arr,int k ,int n ){
    int lsum = 0;
    int rsum =0;
    for(int i=0;i<k;i++)lsum +=arr[i];
    int maxsum = lsum;

    int rIndex = n-1;
    for(int i= k-1;i>=0;i--){
        lsum -=arr[i];
        rsum +=arr[rIndex];
        rIndex--;
        maxsum = max(maxsum,lsum+rsum);
    }
    return maxsum;

}

int main(){
    vector<int>arr= {6,2,3,4,7,2,1,7,1};
    int k = 4;
    int n = 9;
    cout<<fun(arr,k,n);
}