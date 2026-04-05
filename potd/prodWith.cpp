#include<bits/stdc++.h>
using namespace std;

//Product of array except self 

// Approach 1 using divison operator

vector<int>prod(vector<int>&arr){
    int n = arr.size();
    int zcnt = 0;
    int prod = 1;
    for(int i =0;i<n;i++){
        if(arr[i] == 0)zcnt++;
        else prod *= arr[i];
    }
    vector<int>res(n);
    for(int i =0;i<n;i++){
        int num = arr[i];
        if(num!=0){
            if(zcnt>0){
                res[i] = 0;
            }else{
                res[i] = prod/num;
            }
        }else{
            if(zcnt>1){
                res[i] = 0;
            }else{
                res[i] = prod;
            }

        }
    }
    return res;
}

//approach 2 using left and right product arr;
vector<int>prod2(vector<int>&arr){
    int n = arr.size();
    vector<int>left(n);
    vector<int>right(n);
    left[0] = 1;
    for(int i =1;i<n;i++){
        left[i] = left[i-1]*arr[i-1];
    }
    right[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        right[i] = right[i+1]*arr[i+1];
    }
    
    vector<int>res(n);
    for(int i =0;i<n;i++){
        res[i] = right[i] * left[i];
    }
    return res;
}