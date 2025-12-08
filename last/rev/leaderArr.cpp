#include<bits/stdc++.h>
using namespace std;

//leader in array 
//brute force 
vector<int> leader (vector<int>&arr){
    int n =arr.size();
    vector<int>ans;
    for(int i =0;i<n;i++){
        bool leader = true;
        for(int j = i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}


//optimized approach

vector<int> leader2(vector<int>&arr)
{
    int n = arr.size();
    vector<int>ans;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
        ans.push_back(arr[i]);
        maxi=arr[i];
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {16,17,4,3,5,2};
    vector<int>res = leader2(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;   
}