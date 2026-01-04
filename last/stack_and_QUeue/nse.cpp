#include<bits/stdc++.h>
using namespace std;


//next smaller element  through stack
vector<int> nse(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i =0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
