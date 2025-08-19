#include<bits/stdc++.h>
using namespace std;


int bs(vector<int>&arr){
 int n = arr.size();
 int low = 0 , high= n-1;
int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            ans  = min(ans, arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans,arr[low]);
            low=mid+1;
        }else{
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {4,5,6,1,2,3};
    cout<<bs(arr)<<endl;
}