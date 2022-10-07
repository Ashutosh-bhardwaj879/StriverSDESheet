/*
Find the repeating and missing numbers
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:

Input Format:  array[] = {3,1,2,5,3}

Result: {3,4)

Explanation: A = 3 , B = 4
Since 3 is appearing twice and 4 is missing
Example 2:

Input Format: array[] = {3,1,2,5,4,6,7,5}

Result: {5,8)

Explanation: A = 5 , B = 8
Since 5 is appearing twice and 8 is missing
Solution 1: Using Count Sort

Intuition + Approach:

Since the numbers are from 1 to N in the array arr[]

Take a substitute array of size N+1 and initalize it with 0.
Traverse the given array and increase the value of substitute[arr[i]] by one .
Then again traverse the substitute array starting from index 1 to N.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> missRepNumber(vector<int> &A)
{
    int n = A.size() + 1;
    vector<int> freq(n, 0);
    vector<int> ans;
    // i = 0 used here bcoz we are capturing array index which startes from  0
    // not actual elements which startes from 1
    for (int i = 0; i < A.size(); i++)
    {
        freq[A[i]]++;
    }
    // i=0 not used here becuase  elem are from 1 to N
    for (int i = 1; i <= A.size(); i++)
    {
        if (freq[i] == 0 || freq[i] > 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    vector<int> array;
    array = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = missRepNumber(array);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
/**
 * Time Complexity: O(N)

Space Complexity: O(N) As we are making new substitute array
*/