#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int>&arr,int n){
   for(int j=2;j<n;j++){
        int key = arr[j];
        int i =j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
   }
}
int main(){
    vector<int>arr={12,11,13,5,6};
    int n=arr.size();
    insertion(arr,n);
    for(auto &it:arr){
        cout<<it<<" ";
    }
    return 0;
}