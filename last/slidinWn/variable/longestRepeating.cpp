#include<bits/stdc++.h>
using namespace std;

//ps -> longest repeating character element

//given string s and int k you can change at most k characters in the string

int longest (string &s,int k){
    int n = s.size();
    int i =0,j=0;
    int res =0;
    int maxfreq = 0;
    unordered_map<char,int>mpp;
    while(j<n){
        mpp[s[j]]++;    
        maxfreq= max(maxfreq,mpp[s[j]]);

        if(j-i+1 -maxfreq >k){
            mpp[s[i]]--;
            i++;
        }
        res = max(res,j-i+1);
        j++;
    }
    return res;
}


int main(){
    string s = "AABABBA";
    int k = 1;
    cout << "Longest repeating character replacement: " << longest(s, k) << endl;
    

    return 0;
}