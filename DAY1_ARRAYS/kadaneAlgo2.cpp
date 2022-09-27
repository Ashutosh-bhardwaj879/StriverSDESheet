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
*SSolution 2: A better approach

? Approach :

!We can also do this problem using only two for loops, we will avoid 3rd loop which was used in above approach, instead of that we will create new variable curr_sum, which stores the array sum from ith index to jth index.
*/
/*
TODO Time Complexity: O(N^2)
?Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums, vector<int> &sub)
{
    int max_sum = INT_MIN;
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    int i, j;
    for (i = 0; i < n; i++)
    {
        int currSum = 0;
        for (j = i; j < n; j++)
        {
            currSum += nums[j];
            if (currSum > max_sum)
            {
                sub.clear();
                max_sum = currSum;
                sub.push_back(i);
                sub.push_back(j);
            }
        }
    }
    return max_sum;
}
int main()
{
    vector<int> arr{-2, -1, -3, -4, -1, -2, -1, -5, -4};
    vector<int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
}