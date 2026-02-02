#include<bits/stdc++.h>
using namespace std;

//balance parenthesese
bool isBalanced(string &s){
    stack<char>st;
    for(char &ch:s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(st.empty())return false;
            char top = st.top();
            if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}