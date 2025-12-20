#include<bits/stdc++.h>
using namespace std;
//ps ->Minimum moves to balance circular array 

long long minMoves(vector<int>&arr){
    int n = arr.size();
    long long sum = 0;
    bool flag = false;
    for(int it:arr){
        sum += it;
        if(it<0)flag=true;
    }
    if(sum%n !=0){
        return -1;
    }
    long long target = sum/n;
}