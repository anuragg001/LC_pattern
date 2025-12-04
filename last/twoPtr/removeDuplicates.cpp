#include<bits/stdc++.h>
using namespace std;

int remove(vector<int>&arr,int n){
    int j =1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            arr[j]=arr[i];
            j++;
        }
    }
    return j;
}
int cntRotation(vector<int>&arr,int n){
    int low =0,high=n-1;
    while(low<high){
        int mid = (low+high)/2;
        if(arr[low]<arr[high])return low;
        if(arr[mid]>=arr[high]){
            low=mid+1;
        }else{
            high = mid;
        }
        
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ns = remove(arr,n);
    cout<<"Array after removing duplicates:\n";
    for(int i=0;i<ns;i++)cout<<arr[i];
    cout<<"\nCount of rotations in sorted rotated array:\n";
    cout<<cntRotation(arr,n);
    cout<<"\n";
    

    return 0;
}