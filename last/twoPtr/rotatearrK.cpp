#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>&arr,int k){
    int n =arr.size();
    for(int i =0;i<k;i++){
        int temp =arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];

        }
        arr[0]=temp;
    }
}
//by reversing method
void rotate2(vector<int>&arr,int k){
    int n = arr.size();
    k%=n; // for when k>n
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    int k =3;
    rotate2(arr,k);
    for(auto it:arr){
        cout<<it<<" ";
    }
}