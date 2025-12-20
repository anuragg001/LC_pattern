#include<bits/stdc++.h>
using namespace std;
//ps -> minimum removal to make array balance
/*
Input: nums = [2,1,5], k = 2

Output: 1

Explanation:

Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
*/

//bruteforce
