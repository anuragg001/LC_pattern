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
   //using sliding window

   int longestSliding(string &s){
    int n  = s.size();
    int i=0,j=0;
    int maxlen = 0;
    unordered_map<char,int>mpp;
    while(j<n){
        mpp[s[j]]++;
        while(mpp[s[j]]>1){
            mpp[s[i]]--;
            i++;
        }
        maxlen = max(maxlen,j-i+1);
        j++;
    }
    return maxlen;
   }


int main(){
    string s="abcabcbb";
    cout<<longest(s);
}