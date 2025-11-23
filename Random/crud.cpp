#include<bits/stdc++.h>
using namespace std;

string insertAt(string s,int index,char c){
    s.insert(s.begin()+index,c);
    return s;
}
string deleteAt(string s,int index){
    s.erase(s.begin()+index);
    return s;
}
int findChar(string s,char c){
    for(int i=0;i<s.length();i++){
        if(s[i]==c){
            return i;
        }
    }
    return -1;
}
//resverse without using reverse function
string reverseString(string s){
    int n = s.length();
    for(int i =0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    return s;
}
string replaceAt(string s,int index,char c){
    s[index]=c;
    return s;
}

int main(){
    string s;
    cin>>s;
    int index;
    cin>>index;
    char c;
    cin>>c;
    string result = insertAt(s,index,c);
    cout<<result;
}