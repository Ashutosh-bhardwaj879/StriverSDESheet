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
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==arr[i+1])
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
*Solution 1:Using sorting

*Approach: Sort the array. After that, if there is any duplicate number they will be adjacent.So we simply have to check if arr[i]==arr[i+1] and if it is true,arr[i] is the duplicate number.
*/
/*
*Time Complexity:O(Nlogn + N)

*Reason: NlogN for sorting the array and O(N) for traversing through the array and checking if adjacent elements are equal or not. But this will distort the array.

*Space Complexity:O(1)
*/