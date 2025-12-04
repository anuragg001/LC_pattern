#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>&arr){
    int n = arr.size();
    int i =0,j=n-1;
    while(i!=j){
        swap(arr[i],arr[j]);
        i++;
    }
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    rotate(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }

}