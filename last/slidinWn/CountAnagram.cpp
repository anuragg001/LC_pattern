#include<bits/stdc++.h>
using namespace std;

//the problem statement is -> Given a string s and a pattern p,
// find the count of all anagram occurrences of the pattern in the string.


int cnt(string &s,string &pattern){
    int n = s.size();
    int k = pattern.size();
    int i=0,j=0;
    unordered_map<char,int>mpp;
    int mapCnt=0;
    int ans=0;
    for(auto ch:pattern){
        mpp[ch]++;
    }

    while(j<n){
        //calcutaion
        if(mpp.find(s[j])!=mpp.end()){
            mpp[s[j]]--;
            if(mpp[s[j]]==0){
                mapCnt++;
            }
        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            //ansCalcuation
            //why comparing mapCount with map size??
            //ans->if all characters frequency become zero then only we can say that we found an anagram
            if(mapCnt==mpp.size()){
                ans++;
            }
            //slide the window
            if(mpp.find(s[i])!=mpp.end()){
                mpp[s[i]]++;
                //why comparing mpp[s[i]] with 1??
                //ans-> because before sliding the window if frequency was 0 and after sliding it becomes 1 then we need to reduce the mapCnt
                if(mpp[s[i]]==1){
                    mapCnt--;
                }

            }
            i++;
            j++;
        }

    }
    return ans;
}

int main(){
    string s1="forxxorfxdofr";
    string pattern="for";
    cout<<cnt(s1,pattern);
    // Expected output: 3
}