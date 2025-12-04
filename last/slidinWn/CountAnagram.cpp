#include<bits/stdc++.h>
using namespace std;

int cntAnagram(string &s1,string &pattern){
    int n =s1.size();
    int k = pattern.size();
    unordered_map<char,int>mpp;
    int i=0,j=0;
    int cnt =0;
    for(auto ch:pattern){
        mpp[ch]++;
    }
    int match =0;
    while(j<n){
        if(mpp.find(s1[j])!=mpp.end()){
            mpp[s1[j]]--;
            if(mpp[s1[j]]==0){
                match++;
            }

        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(match==mpp.size()){
                cnt++;
            }
            if(mpp.find(s1[i])!=mpp.end()){
                mpp[s1[i]]++;
                if(mpp[s1[i]]==0){
                    match--;
                }
                // mpp[s1[i]]++;
            }
            i++;
            j++;
        }

    }
    return cnt;
}

int cnt(string &s,string &pattern){
    int n = s.size();
    int k = pattern.size();
    unordered_map<char,int>mpp;
    int cnt = 0;
    int i =0,j=0;
    int match=0;
    for(auto ch:pattern){
        mpp[ch]++;
    }

    while(j<n){
        if(mpp.find(s[j])!=mpp.end()){
            mpp[s[j]]--;
            if(mpp[s[j]]==0){
                match++;
            }
        }
        //expand the window
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(match ==mpp.size()){
                cnt++;
            }
            //exclude i basically shrinking the window
            if(mpp.find(s[i])!=mpp.end()){
                mpp[s[i]]++;
                if(mpp[s[i]]==0){
                    match--;
                }
            }
            i++;
            j++;
        }


    }
    return cnt;
}

int main(){
    string s1="forxxorfxdofr";
    string pattern="for";
    cout<<cnt(s1,pattern);
    // Expected output: 3
}