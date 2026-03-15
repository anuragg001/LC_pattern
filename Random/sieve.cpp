#include<bits/stdc++.h>
using namespace std;


//prime number thorugh sieve of eratosthenes

vector<int> sieve (int n ){
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]= false;
    for(int i =2;i*i<=n;i++){
        if(prime[i]){
            for(int j = i*i ; j<=n; j+=i){
                prime[j] = false;

            }
        }
    }
    vector<int>res;
    for(int i =2;i<=n;i++){
        if(prime[i]){
            res.push_back(i);
        }

    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int>res = sieve(n);
    for(int &i:res){
        cout<<i<<" ";
    }
}