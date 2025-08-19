#include <bits/stdc++.h>
using namespace std;

// brute force ( reframing the qustion)
int fun(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int zCnt = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                zCnt++;
            if (zCnt <= k)
            {
                maxi = max(maxi, j - i + 1);
            }
            else
                break;
        }
    }
    return maxi;
}


int fun2(vector<int>&arr,int k){
    int l =0;
    int r =0;
    int maxi =0;
    int n = arr.size();
    int zCnt = 0;
    while(r<n){
        if(arr[r]==0)zCnt++;

        while(zCnt>k){
        if(arr[l]==0)zCnt--;
        l++;
        }
        if(zCnt<=k){
            maxi = max(maxi,r-l+1);
        }
        r++;
    }
    return maxi;
}

int fun3(vector<int>&arr,int k){
    int l =0;
    int r =0;
    int maxi =0;
    int n = arr.size();
    int zCnt = 0;
    while(r<n){
        if(arr[r]==0)zCnt++;

        if(zCnt>k){
        if(arr[l]==0)zCnt--;
        l++;
        }
        if(zCnt<=k){
            maxi = max(maxi,r-l+1);
        }
        r++;
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << fun3(arr, k);
}