/*
Length of the longest subarray with zero Sum
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
Example 1:

Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

Result: 5

Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!
Example 2:

Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}

Result: 8

Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8
Example 3:

Input Format: N = 3, array[] = {1, 0, -5}

Result: 1

Subarray : {0}
Length of longest subarray = 1
Example 4:

Input Format: N = 5, array[] = {1, 3, -5, 6, -2}

Result: 0

Subarray: There is no subarray that sums to zero
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // here also we are doing i + 1 at ==0
        //TC = {0}
        //TC = {-3,3}
        if (sum == 0)
        {
            ans = i + 1;
        }
        else
        {
            //Tc - {9,-,3,3}
            if (mp.find(sum) != mp.end())
            {
                // jahan pe sum mila tha last minus
                // abi jahan pe i pointed hai
                // we are not putting this sum again
                // because we want to find longest
                // suubarray
                ans = max(ans, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    int n = arr.size();
    cout << solve(arr, n);
    return 0;
}
/**
 * Time Complexity: O(N), as we are traversing the array only once

Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
*/