#include<bits/stdc++.h>
using namespace std;

//remove k digits to make smallet number 

/*
hadnling some edge cases
1. if k is equal to size of number then return 0
2. if after removing k digits the number starts with 0 then remove leading 0s
3. if number is sorted in increasing order then remove last k digits
*/

string remove(string num,int k){
    int n = num.size();
    if(k==n)return "0";
    stack<char>st;
    for(int i =0;i<n;i++){
        while(!st.empty() && k>0 && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);

    }
    // if k is still left , remove from last
    while(k>0){
        st.pop();
        k--;
    }

    //construct the number from stack
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    while(ans.size()>1 && ans.back()=='0'){ //remove leading 0s
        ans.pop_back();
    }
    
    reverse(ans.begin(),ans.end());
    
    if(ans=="")return "0";
    return ans;


}