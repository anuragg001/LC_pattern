#include<bits/stdc++.h>
using namespace std;
//ps ->Minimum moves to balance circular array 
//In one move, you can increment n - 1 elements of the array by 1.
/*
Input: arr = [0,2,3]
Output: 3
Explanation:
Start with arr = [0,2,3].
Increment the first two elements in the array by 1. Now arr = [1,3,3].
Increment the first two elements again to get arr = [2,4,3].
Increment the last two elements in the array by 1. Now arr = [3,4,4].
It can be shown that we cannot reach a balanced array in less than 3 moves.
*/

typedef long long ll;
long long minMoves(vector<int>&balance){
    int n  = balance.size();
    ll sum = 0;
    int negIdx = -1;
    for(int i =0;i<n;i++){
        sum += balance[i];
        if(balance[i]<0){
            negIdx = i;
        }

    }
    if(negIdx == -1){
        return 0;
    }
    if(sum<0){
        return -1;
    }
    ll moves = 0;
    int dist =1;
    while(balance[negIdx]<0){
        int right = (negIdx +dist)%n;
        int left = (negIdx - dist +n)%n;

        ll available = balance[right]+balance[left];
        if(left==right)
        available -= balance[right];
        ll needed = -balance[negIdx];
        ll taken = min(available, needed);

        moves += taken *dist;
        balance[negIdx] == taken;
        dist++;
    }
    return moves;
}

int main(){
    vector<int> balance = {5,1,-4};
    cout<<minMoves(balance);
}