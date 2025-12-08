#include<bits/stdc++.h>
using namespace std;

//rearraange elements by sign equal numbers of sign arr are prpesent n/2 +ive and n/2 -ive

vector<int> rearrange(vector<int>&arr){
    int n = arr.size();
    int posIdx = 0;
    int negIdx =1;
    vector<int>ans(n,0);
    for(int i =0;i<n;i++){
        if(arr[i]<0){
            ans[negIdx]=arr[i];
            negIdx+=2;
        }else{
            ans[posIdx]=arr[i];
            posIdx+=2;
        }
    }
    return ans;
}


int main(){
    vector<int>arr = {3,1,-2,-5,2,-4};
    vector<int>res = rearrange(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}