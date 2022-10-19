/**
Two Sum : Check if a pair with given sum exists in Array
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
 */
// naive approach
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.emplace_back(i);
                res.emplace_back(j);
                break;
            }
        }
        // this if loop is needed if want to store only 1 set of result
        if (res.size() == 2)
        {
            break;
        }
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
    vector<int> arr = {2, 7, 3, 6};
    int target = 9;
    vector<int> result;
    result = twoSum(arr, target);

    printVector(result, result.size());
    return 0;
}
/*
Time Complexity : O(N2)

Space Complexity : O(1)
*/