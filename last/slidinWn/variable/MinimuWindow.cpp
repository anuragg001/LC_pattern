#include<bits/stdc++.h>
using namespace std;


//Minimum Window Substring
// we have given two strings s and t
// we have to find the minimum window in s which will contain all the characters in t
//Soultuion:
/*
    we will use variable sliding window approach
    we will use a map to store the frequency of characters in t
    then we will expand the window by moving j pointer and include characters in the map
    when the window contains all characters of t we will try to minimize the window by moving i pointer
    keypoints-> 
    1. if the char freq is in negative in the map it means we have extra char in the window
    2. we will maintain a count variable to check how many characters of t are matched
    3. when count==t.size() it means we have a valid window

*/
//we have to return the substring

string minWindow(string &s,string &t){
    int total = t.size();
    int n = s.size();
    unordered_map<char,int>mpp;
    for(char ch:t){
        mpp[ch]++;
    }
    int i=0,j=0,ans=INT_MAX,index=-1;
    //here ans is storing minimum length of substring 

    while(j<n){
        mpp[s[j]]--; //decerese the cnt of char
        if(mpp[s[j]]>=0){
            total--; // if cnt is not neg then decrese total
        }
            //can we decrease the size of window
            while(total==0 && i<=j){
                //update the length of substri
                if(ans>j-i+1){
                    ans =j-i+1;
                    index=i;
                }
                mpp[s[i]]++; //beofre removing the char from window increse its cnt in map
                if(mpp[s[i]]>0){
                    total++;
                }
                i++; //remove the char from window
            }
        //incerase the size of window
            j++;
    }
    if(index==-1){
        return "";
    }
    else{
        return s.substr(index,ans);
    }
}

int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);
    //op->4
}


