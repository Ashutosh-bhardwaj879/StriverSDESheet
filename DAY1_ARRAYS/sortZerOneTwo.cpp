/*
!Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

?Example 1:

*Input: nums = [2,0,2,1,1,0]
*Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Input: nums = [0]
*/
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (nums[mid])
        {

        // If the element is 0
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

int main()
{
    vector<int> arr;
    arr = {1, 1, 1, 2, 2, 2, 0, 0, 0};
    sortColors(arr);
    for (int i = 0; i < arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
/*
?Time Complexity: O(N)
!Space Complexity: O(1)
*/