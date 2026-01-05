#include<bits/stdc++.h>
using namespace std;

// Maximum matrix sum 
/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above


Approach -> traverse the entire matrix and count the number of negative elements
edge case->
for odd negative counnt we have leave one negative element with smallest abosoute value 
what if odd negative and a 0 present -> we can convert that smallest abosulute value negative to positive using 0 
*/

int sum(vector<vector<int>>&arr){
    int n = arr.size();
    int cnt = 0;
    long long sum = 0;
    int mini = INT_MAX;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<0){
                cnt++;
            }
            //calculate sum of absolute values
            sum += abs(arr[i][j]);
            //fint the minimum absolute value
            mini = min(mini,abs(arr[i][j]));

        }
    }
    // if negative count is odd , subtract twice the minimum absolute value from sum 
    //why twice -> because we have already added it once in sum of absolute values
    if(cnt%2==1){
        sum -= (2*mini);
    }
    return sum;
}

int main(){
    vector<vector<int>>arr = {
       {1,2,3},{-1,-2,-3},{1,2,3}
    };

    cout<<sum(arr);
    return 0;
}