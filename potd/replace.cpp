#include<bits/stdc++.h>
using namespace std;


//leader in array 

int main(){
    vector<int>arr = {7,12,3,5,2,1};
    int n = arr.size();
    vector<int>res;
    int  mxright = arr[n-1];
    res.push_back(mxright);
    for(int i =n-2;i>=0;i--){
        if(arr[i]>=mxright){
            mxright = arr[i];
            res.push_back(arr[i]);
        }
    }
    reverse(arr.begin(),arr.end());
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
