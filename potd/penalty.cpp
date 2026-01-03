#include<bits/stdc++.h>
using namespace std;

long long maximumScore(vector<int>& arr) {
        int n = arr.size();
        vector<long long > suffix(n+1);
        suffix[n] = LLONG_MAX;
        for(int i = n-1; i >= 0; i--){
            suffix[i] = min(suffix[i+1], (long long)arr[i]);
        }
        long long prefix = 0;
        long long ans = LLONG_MIN;
        for(int i = 0; i < n-1; i++){
            prefix += arr[i];
            long long score = prefix - suffix[i+1];
            ans = max(ans, score);
        }
        return ans;
    }


int main(){
    vector<int> arr = {2,3,1,4,5};
    cout<<maximumScore(arr)<<endl;
}

  