#include<bits/stdc++.h>
using namespace std;

int longest(vector<int>&arr,int n,int k){
    int sum =0;
    int l=0,r=0;
    int maxlen =0;

    while(r<n){
        sum +=arr[r];

        while(sum>k){
            sum -=arr[l];
            l++;
        }
        if(sum<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }

}

int longest2(vector<int>&arr,int n ,int k){
    int l=0;
    int maxlen =0;
    int sum =0;

    for(int r =0;r<n;r++){
        sum+=arr[r];

        while(l<=r && sum>k){
            sum -=arr[l];
            l++;
        }
        maxlen = max(maxlen,r-l+1);
    }
    return maxlen;
}



int main(){
vector<int>arr={1,2,1,0,1,1,0};
int k=4;
cout<<longest2(arr,arr.size(),k);
}