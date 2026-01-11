#include<bits/stdc++.h>
using namespace std;

// Maximum number of words you can type 
/*
here is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
*/

int canBetype(string &word,string &broken){
    bool mpp[26]={false};
    for(char &ch:broken){
        mpp[ch-'a']=true;
    }
    bool cantype = true;
    int res = 0;
    for(char &ch:word){
        if(ch==' '){
            //word ended
            if(cantype){
                res++;
            }
            cantype = true; //reset for next word
        }else{
            if(mpp[ch-'a']){
                cantype = false; //cannot type this word
            }

        }

    }

    //why this check? -> because last word may not be followed by space e.g "hello world"
    //for last word
    if(cantype){
        res++;
    }
    return res;


}