/*
!Find the duplicate in an array of N+1 integers
!Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

?Examples:

*Example 1:

*Input: arr=[1,3,4,2,2]

*Output: 2
*https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
*Explanation: Since 2 is the duplicate number the answer will be 2.

*Example 2:

*Input: [3,1,3,4,2]

*Output:3

*Explanation: Since 3 is the duplicate number the answer will be 3.
*/
#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
    return 0;
}

// Solution 3: Linked List cycle method
// TC = O(N)
// SC = O(1)