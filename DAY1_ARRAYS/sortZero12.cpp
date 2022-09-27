/*
*https://www.javatpoint.com/sort-an-array-of-0s-1s-and-2s
!Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
?https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
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

void sort012(vector<int> &arr, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int j;
    for (j = 0; j < count0; j++)
    {
        arr[j] = 0;
    }
    for (j = count0; j < count0 + count1; j++)
    {
        arr[j] = 1;
    }
    for (j = count0 + count1; j < n; j++)
    {
        arr[j] = 2;
    }
}
void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2, 0, 0, 0};
    int n = arr.size();
    sort012(arr, n);
    print(arr, n);
    return 0;
}