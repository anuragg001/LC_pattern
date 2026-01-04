#include<bits/stdc++.h>
using namespace std;

//brute force (reframing the question)
int fun(vector<int>&arr){
    int n  = arr.size();
    int maxi = 0;

    for(int i =0;i<n;i++){
        unordered_set<int>st;
        for(int j =i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=2) maxi = max(maxi,j-i+1);
        }
    }
    return maxi;
}

//optimal
int fun2(vector<int>&arr){
    int r =0,l=0;
    int n = arr.size();
    int maxi =0;
    unordered_map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;

        if(mpp.size()>2){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0)mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size()<=2){
            maxi =max(maxi,r-l+1);
        }
        r++;
    }
    return maxi;
}


int main(){
    vector<int>arr={1,2,3,2,2};
    cout<<fun2(arr);
}