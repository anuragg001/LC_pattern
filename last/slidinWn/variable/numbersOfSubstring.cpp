#include<bits/stdc++.h>
using namespace std;

//uniqiue question not directly sliding window
//number of substring containing all three characters a,b,c


int number(string &s){
    int n=s.size();
    int lastseen[3]={-1,-1,-1}; //to store last seen index of a,b,c
    int cnt =0;

    for(int i =0;i<n;i++){
        lastseen[s[i]-'a']=i; //update last seen index
        
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
            cnt = cnt +(1+min({lastseen[0],lastseen[1],lastseen[2]}));

        }
    }
    return cnt;
}