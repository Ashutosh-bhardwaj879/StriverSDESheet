// https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
/**
 * Two Sum : Check if a pair with given sum exists in Array
Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

Note: Assume that there is exactly one solution, and you are not allowed to use the same element twice. Example: If target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:

Input: nums = [2,7,11,15], target = 9

Output: [0,1]

Explanation: Because nums[0] + nums[1] == 9,
which is the required target, we return
indexes [0,1]. (0-based indexing)
Example 2:

Input Format: nums = [3,2,4,6], target = 6

Output: [1,2]

Explanation: Because nums[1] + nums[2] == 6,
which is the required target, we return
indexes [1,2].
 * Solution 3: Hashing (Most efficient)

Approach: We can solve this problem efficiently by using hashing. We’ll use a hash-map to see if there exists a value target – x for each value x. If target – x is found in the map, can return current element x’s index and (target-x)’s index

This can be done in constant time.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    int n = arr.size();

    unordered_map<int, int> mp;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            res.emplace_back(i);
            res.emplace_back(mp[target - arr[i]]);
            return res;
        }
        mp[arr[i]] = i;
    }
    return res;
}
void printVector(vector<int> &result, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}
int main()
{
    vector<int> arr = {3, 2, 1, 4};
    int target = 5;
    vector<int> result = twoSum(arr, target);
    printVector(result, result.size());
    return 0;
}
/**
 * Time Complexity: O(N)

Space Complexity: O(N)
*/