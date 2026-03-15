#include<bits/stdc++.h>
using namespace std;


string word(string s){
    int n = s.size();
    int i = 0;
    int l = 0 , r = 0;
    reverse(s.begin(),s.end());
    while(i<n){
        while(i<n && s[i]!=' '){
            s[r]= s[i];
            r++ , i++;
        }
        if(l<n){
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
        }
    }
    s = s.substr(0,r-1);
    return s;
}