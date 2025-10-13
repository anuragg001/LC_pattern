#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    int b;
    cin>>b;
    double ans=1;
    double m =b; //for neg power
    while(b>0){
        if(b%2==1){
            ans = ans*a;
            b=b-1;
        }else{
            b=b/2;
             a*=a;
        }
        if(b<0){
            ans = 1/ans;
            break;
        }
    }
    cout<<ans;
}