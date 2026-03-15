#include<bits/stdc++.h>
using namespace std;

//majority element through moores' vooting algo 

int find(vector<int>&arr){
    int n = arr.size();
    int cnt = 0;
    int elem;

    for(int i =0;i<n;i++){
        if(cnt==0){
            elem = arr[i];  
            cnt = 1;
        }
        else if(arr[i]==elem){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    return elem;
}