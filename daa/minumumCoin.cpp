#include<bits/stdc++.h>
using namespace std;

//greedyy approach to find minimum number of coins

int main(){
    vector<int>coins={1,5,10,25};
    int amount;
    cin>>amount;
    sort(coins.rbegin(),coins.rend());
    int cnt = 0;
    for(auto c:coins){
        if(amount==0)break;
        cnt +=amount/c;
        amount = amount%c;
    }
    cout<<cnt;
    return 0;
}

//why fails for all denominations?
//Ans -> because greedy approach works for specific denominations only like US coins
//eg: 1,5,10,25
//What is canonical coin systems
//but fails for denominations like 1,3,4
//eg: amount=6
//greedy approach will give 4+1+1=3 coins
//but optimal solution is 3+3=2 coins
//to solve for all denominations we use dynamic programming approach

//refer to daa/minumumCoinDP.cpp for dynamic programming approach