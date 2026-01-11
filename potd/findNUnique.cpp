#include<bits/stdc++.h>
using namespace std;

// find n unique integer sum up to 0
/*
Given an integer n, return any array containing n unique integers such that they add up to 0.
*/

//bruteforce
vector<int> zero(int n){
    vector<int>res;
    int sum = 0;
    for(int i =1;i<n;i++){
        res.push_back(i);
        sum +=i;
    }
    res.push_back(-sum);
    return res;
}
6