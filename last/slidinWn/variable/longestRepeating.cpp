#include<bits/stdc++.h>
using namespace std;

//ps -> longest repeating character element

//given string s and k you can change at most k characters in the string

int longest(string &s,int k){
    int n = s.size();
    int maxlen=0;
    int i=0,j=0;
    unordered_map<char,int>mpp;
    int maxf=0; //to store maximum frequency of a character in current window
    while(j<n){
      mpp[s[j]]++;
      maxf= max(maxf,mpp[s[j]]);
        int windowlen = j-i+1;
        while(windowlen-maxf>k){
            mpp[s[i]]--;
            //reset the maxf 
            //and recalculate the maxf
            maxf=0;
            for(auto it:mpp){
                maxf=max(maxf,it.second);
            }
            //move the left pointer
            i++;
            windowlen = j-i+1; // recalculate window length after moving i
        }
        //update the maxlen
        maxlen= max(maxlen,windowlen);
        j++;

    }
    return maxlen;
    
}




int main(){
    string s = "AABABBA";
    int k = 1;
    cout << "Longest repeating character replacement: " << longest(s, k) << endl;
    
    s = "ABAB";
    k = 2;
    cout << "Longest repeating character replacement: " << longest(s, k) << endl;
    
    return 0;
}