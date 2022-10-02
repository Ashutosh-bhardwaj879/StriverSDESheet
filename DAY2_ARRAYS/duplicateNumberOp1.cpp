/*
!Find the duplicate in an array of N+1 integers
!Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

?Examples:

*Example 1:

*Input: arr=[1,3,4,2,2]

*Output: 2

*Explanation: Since 2 is the duplicate number the answer will be 2.

*Example 2:

*Input: [3,1,3,4,2]

*Output:3

*Explanation: Since 3 is the duplicate number the answer will be 3.
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        if(freq[arr[i]] == 0)
        {
            freq[arr[i]] += 1;
        }
        else
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 2};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
    return 0;
}
/*
*Time Complexity: O(N), as we are traversing through the array only once.

*Space Complexity: O(N), as we are using extra space for frequency array.
*/
/*
!Solution 2 : Using frequency array

!Approach : Take a frequency array of size N + 1 and
!initialize it to 0. Now traverse through the array and if the frequency
!of the element is 0 increase it by 1, else if the frequency is not 0 then that 1element is the required answer.
*/