#include<bits/stdc++.h>
using namespace std;

//next prermutaion of a given array
vector<int> next(vector<int>&arr){
    int n = arr.size();
    int idx = -1;
    //find the break point from right side 
    for(int i =n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx= i;
            break;
        }
    }

    //edge case if idx is -1 means array is in descending order
    if(idx==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
     //find the just greater element than arr[idx] from right side
     for(int i =n-1;i>=idx;i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
     }
        //reverse the array from idx+1 to end
        reverse(arr.begin()+idx+1,arr.end());
        return arr;

}


int main(){
    vector<int>arr = {1,2,3};
    vector<int>res = next(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;

}
