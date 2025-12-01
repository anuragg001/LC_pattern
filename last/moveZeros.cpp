#include<bits/stdc++.h>
using namespace std;

//using i and j ptr 
void zero(vector<int>&arr,int n){
    int j=-1;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1)return;

    for(int i =j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

//thorugh count of zeros in single traversal
void zerosCnt(vector<int>&arr,int n){
    int j = 0;
    for(int i =0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    zerosCnt(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i];
}