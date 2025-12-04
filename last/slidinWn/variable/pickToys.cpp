#include<bits/stdc++.h>
using namespace std;

//pick toys problem 
// we have to pick maximum toys from string such that we can pick at max 2 different types of toys
// we will use variable sliding window and map to store frequency of toys
//just like we have solve the question of longest substring with k unique characters


int maxToys(string &s){
    int n = s.size();
    int maxlen =0;
    int i=0,j=0;
    unordered_map<char,int>mpp;

    while(j<n){
        mpp[s[j]]++;

        if(mpp.size()<=2){
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        else if(mpp.size()>2){
            while(mpp.size()>2){
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


//similary there is question on leetcode named as fruit into baskets
//can we solve it with this approach
// Yes we can 

int fruits(vector<int>&fruits){
    int n = fruits.size();
    int maxlen =0;
    int i=0,j=0;
    unordered_map<int,int>mpp;

    while(j<n){
        mpp[fruits[j]]++;

        if(mpp.size()<=2){
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        else if(mpp.size()>2){
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxlen;
}