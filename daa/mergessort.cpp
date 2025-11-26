#include<bits/stdc++.h>
using namespace std;
//merge sort using divide and conquer approac


int merge(vector<int>&arr,int low,int mid,int high){
    

}
int main(){
    vector<int>arr={12,11,13,5,6,7};
    int n=arr.size();   
    mergeSort(arr,0,n-1);
    for(auto &it:arr){
        cout<<it<<" ";
    }
    return 0;
}