#include<bits/stdc++.h>
using namespace std;

// Minimum number of k consecutive bit flip to convert all bits to 1

//bruteforce;

int minFlip(vector<int>&arr,int k){
    int n = arr.size();
    int flip =0;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            if(i+k-1>=n)return -1;
            for(int j =i;j<=i+k-1;j++){
                arr[j]= !arr[j];
            }
            flip++;
        }
    }
    return flip;
}

//optimised approach o(n) time
/*
 the approach is to use a queue to keep track of the flips that are currently affecting the current position.
 when we reach a position i , we check if the number of flips affecting this position is even or odd.
 if it is even , the bit remains the same , if it is odd , the bit is flipped.
 if the current bit (after considering the flips) is 0 , we need to flip it 
  by adding a new flip that will affect the next k bits starting from i .

*/
int minFlip2(vector<int>&arr,int k){
    int n = arr.size();
    queue<int>q;
    int flip = 0;

    for(int i =0;i<n;i++){

        //remove the flips which are out of current range
        if(!q.empty() && q.front()==i){
            q.pop();
        }

        //check the current bit after considering the flips 
        int currBit = arr[i];
        if(q.size()%2==1){
            currBit = !currBit;
        }

        // if the current bit is 0 , we need to flip it
        if(currBit==0){
            if(i+k>n)return -1 ;//not possible to flip
            q.push(i+k); //add a new flip that will affect next k bits
            flip++;
        }
    }
    return flip;
}

int main(){
    vector<int>arr = {0,0,0,1,0,1,1,0};
    int k =3;
    cout<<minFlip2(arr,k);
    return 0;
}