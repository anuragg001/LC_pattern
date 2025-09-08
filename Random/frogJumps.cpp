#include<bits/stdc++.h>
using namespace std;
//through recursion
int solve(vector<int> &arr,int n){
    if(n<1)return 0;
    int fs = solve(arr,n-1)+abs(arr[n]-arr[n-1]);
    int ss;
    if(n>1)
    ss= solve(arr,n-2)+abs(arr[n]-arr[n-2]);
    return min(fs,ss);
}

int main(){
    vector<int> arr={10,20,30,10};
    int n=arr.size();
    cout<<solve(arr,n-1);
    return 0;
}
//op -> 20