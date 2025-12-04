#include<bits/stdc++.h>
using namespace std;


int longest(string&s){
    int n = s.size();
    int maxlen=0;
    for(int i =0;i<n;i++){
        int hash[256]={0};
        int currlen =0;
        for(int j =i;j<n;j++){
            if(hash[s[j]]==1){
                break;
            }
            currlen=j-i+1;
            maxlen=max(maxlen,currlen);
            hash[s[j]]=1;
        }
    }
    return maxlen;
}
   


int main(){
    string s="abcabcbb";
    cout<<longest(s);
}