/*
*Kadane’s Algorithm : Maximum Subarray Sum in an Array
!Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
!has the largest sum and return its sum and print the subarray.
?https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
*Examples:

*Example 1:

*Input: arr = [-2,1,-3,4,-1,2,1,-5,4]

*Output: 6

*Explanation: [4,-1,2,1] has the largest sum = 6.

*Examples 2:

*Input: arr = [1]

*Output: 1

*Explanation: Array has only one element and which is giving positive sum of 1.
*/
/*
*Solution 1: Naive Approach

?Approach: Using three for loops, we will get all possible subarrays in two loops and their sum in another loop, and then return the maximum of them.
*/
/*
TODO Time Complexity: O(N^3)
?Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums, vector<int> &subarray)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    if (n == 1)
    {
        return nums[0];
    }
    int i, j;
    for (i = 0; i <= n - 1; i++)
    {
        for (j = i; j <= n - 1; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + nums[k];
                if (sum > maxSum)
                {
                    subarray.clear();
                    maxSum = sum;
                    subarray.push_back(i);
                    subarray.push_back(j);
                }
            }
            // if(sum > maxSum)
            // {
            //     subarray.clear();
            //     maxSum = sum;
            //     subarray.push_back(i);
            //     subarray.push_back(j);
            // }
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}