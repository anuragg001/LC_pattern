#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
//sum of minimum subarr

//brute force
int summ(vector<int>&arr){
    int n = arr.size();
    int ttlSum = 0;
    for(int i =0;i<n;i++){
        int mn = arr[i];
        for(int j = i;j<n;j++){
            mn = min(mn,arr[j]);
            ttlSum = (ttlSum + mn)%MOD;
        }
    }
    return ttlSum;
}


//thorugh stack and nse and pse function

vector<int> nse(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i =0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> pse(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i =n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}


int sum2(vector<int>&arr){
    int n = arr.size();
    vector<int>nextSmaller = nse(arr);
    vector<int>prevSmaller = pse(arr);
    int ttl = 0;
    for(int i =0;i<n;i++){
        int next = nextSmaller[i]==-1?n:nextSmaller[i];
        int prev = prevSmaller[i]==-1?-1:prevSmaller[i];
        int cnt = (i-prev)*(next-i);
        ttl = (ttl +(arr[i]*cnt)%MOD)%MOD;

    }
    return ttl;
}

int main(){
    vector<int>arr = {3,1,2,4};
    cout<<summ(arr);
}