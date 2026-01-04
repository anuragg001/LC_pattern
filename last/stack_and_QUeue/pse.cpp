#include<bits/stdc++.h>
using namespace std;

//previous smalleer element through stack

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