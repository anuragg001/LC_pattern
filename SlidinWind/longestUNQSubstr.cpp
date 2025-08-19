#include<bits/stdc++.h>
using namespace std;

//bruteforce 
int fun (string &s){
    int maxi =0;

    for(int i =0;i<s.size();i++){
        char hash[256]={0};
        for(int j =i;j<s.size();j++){
            if(hash[s[j]]==1)break;
            hash[s[j]]=1;
            int len = j-i+1;
            maxi= max(maxi,len);
        }
    }
    return maxi;
}

int main(){
    string s = "abadab";
    cout<<fun(s);
}