#include<bits/stdc++.h>
using namespace std;

//count square sum triples

//given n count the number of triples (a,b,c) such that a^2 + b^2 = c^2 and 1<= a,b,c <= n

//bruteforce approach
int count(int n){
    int cnt =0;
    for(int a =1;a<=n;a++){
        for(int b =1;b<=n;b++){
            for(int c =1;c<=n;c++){
                if(a*a + b*b == c*c){
                    cnt++;
                }
            }
        }
    }
}

