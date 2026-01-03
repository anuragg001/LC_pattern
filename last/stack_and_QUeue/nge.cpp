#include<bits/stdc++.h>
using namespace std;

//next greater element

//brute force

vector<int>nge(vector<int>&arr){
    int n = arr.size();
    vector<int>res(n,-1);
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]>arr[i]){
                res[i]=arr[j];
                break;
            }
        }
    }
    return res;
}

// optimal through stack
vector<int>nge2(vector<int>&arr){
    int n = arr.size();
    vector<int>res(n,-1);
    stack<int>s;
    for(int i = n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            res[i]=s.top();
        }
        s.push(arr[i]);
    }
    return res;
}
// circular nge
vector<int>cnge(vector<int>&arr){
    int n = arr.size();
    vector<int>res(n,-1);
    stack<int>s;
    for(int i = 2*n-1;i>=0;i--){
        int idx  = i%n;
        while(!s.empty() && s.top()<=arr[idx]){
            s.pop();
        }
        if(!s.empty()){
            res[idx]=s.top();
        }
        s.push(arr[idx]);
    }
    return res;
}