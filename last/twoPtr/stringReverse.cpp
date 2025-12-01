#include<bits/stdc++.h>
using namespace std;

string reverese(string &s){
    int left =0;
    int right = s.length()-1;
    while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    cout<<reverese(s);
}