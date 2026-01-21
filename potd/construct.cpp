#include<bits/stdc++.h>
using namespace std;

/*
Construct the Minimum bitwise array 1
You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.
*/

// brute force approach 

vector<int>bit(vector<int>&arr){
    int n = arr.size();
    vector<int>res(n,-1);
    for(int i =0;i<n;i++){
        for(int x = 0;x<arr[i];x++){
            if((x | (x+1))==arr[i]){
                res[i]=x;
                break;
            }

        }

    }
    return res;
}

//optimal approach
//observing the pattern we can say that if num[i] has consecutive set bits then it is not possible to find such x
// eg:3(11),7(111),11(1011) etc
vector<int>bitwise(vector<int>&arr){
    int n = arr.size();
    vector<int>res(n,-1);
    for(int i =0;i<n;i++){
        int x = arr[i];
        // check if x has consecutive set bits
        if((x & (x>>1))==0){
            res[i]= x & (~(x+1));
        }
    }
    return res;
}

int main(){
    vector<int>nums={2,3,5,7};
    vector<int>ans=bitwise(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
//op -> 