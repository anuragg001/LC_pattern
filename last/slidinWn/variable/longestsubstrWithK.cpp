#include<bits/stdc++.h>
using namespace std;

//longest substring with k unique charactere 
//solution-> we ll use variable sliding window and to store uniqiue character we will use 
// a map 

int longestKUnique(string &s,int k){
    int n =s.size();
    int maxlen = 0;
    int i=0,j=0;
    unordered_map<char,int>mpp;

    while(j<n){
        mpp[s[j]]++;

        if(mpp.size()<k){
            j++;
        }

        else if(mpp.size()==k){
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        else if (mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);

                }
                i++;
            }
            j++;
        }

    }
    return maxlen;

}

int main(){
    string s="aabacbebebe";
    int k=3;
    cout<<longestKUnique(s,k);  
    //output:7
}


//similiary longest substring wihtout repeating character can be solved using same approach
// just we have to check mpp.size()==j-i+1 i.e all char are unique


int longest2(string &s){
    int n = s.size();
    int maxlen = 0;
    int i =0,j=0;
    unordered_map<char,int>mpp;

    while(j<n){
        mpp[s[j]]++;
        if(mpp.size()==j-i+1){
            maxlen= max(maxlen,j-i+1);
            j++;
        }
        else if(mpp.size()<j-i+1){
            while(mpp.size()<j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxlen;
}
