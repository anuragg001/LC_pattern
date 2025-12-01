#include<bits/stdc++.h>
using namespace std;

pair<int,int> sum(vector<int>&arr,int n,int target){
    sort(arr.begin(),arr.end());
    int left =0;
    int right = n-1;
    while(left<right){
        int sum = arr[left]+arr[right];
        if(sum==target){
            return {arr[left],arr[right]};
        }else if(sum<target){
            left++;
        }else{
            right--;
        }
    }
    return {-1,-1};
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int>ans = sum(arr,n,target);
    if(ans.first==-1 && ans.second==-1){
        cout<<"No such elements found\n";
    }else{
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}