#include<bits/stdc++.h>
using namespace std;


/*
Minimum pair removal to sort array 1
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Approach -> Brute force 
 Algorithm:
1. Initialize a counter to keep track of the number of operations performed.
2. While the array is not non-decreasing:
    a. Find the adjacent pair with the minimum sum.
    b. Replace this pair with their sum.
    c. Increment the counter.


*/

int minPair(vector<int>&arr){
    int n = arr.size();
    int minSum = INT_MAX;
    int idx =-1;
    for(int i =0;i<n-1;i++){
        int sum = arr[i]+arr[i+1];
        if(sum<minSum){
            minSum = sum;
            idx = i;
        }
    }
    return idx;
}
int minOperationsToSortArray(vector<int>& arr) {
   int n  = arr.size();
   int opr = 0;
   while(is_sorted(arr.begin(),arr.end())){
    int idx = minPair(arr);
    arr[idx] = arr[idx]+arr[idx+1];
    arr.erase(arr.begin()+idx+1);
    opr++;
   }
   return opr;
}

