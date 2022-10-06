/*
 *Find the repeating and missing numbers
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:
https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
Input Format:  array[] = {3,1,2,5,3}

Result: {3,4)

Explanation: A = 3 , B = 4
Since 3 is appearing twice and 4 is missing
Example 2:

Input Format: array[] = {3,1,2,5,4,6,7,5}

Result: {5,8)

Explanation: A = 5 , B = 8
Since 5 is appearing twice and 8 is missing
*/
// Using Mathematics

#include <bits/stdc++.h>
using namespace std;

vector<int> missRepNumber(vector<int> &A)
{
    long long int n = A.size();
    long long int S = n * (n + 1) / 2;
    long long int P = n * (n + 1) * (2 * n + 1) / 6;

    for (int i = 0; i < A.size(); i++)
    {
        S -= A[i];
        P -= A[i] * A[i];
    }
    long long int missing = 0;
    long long int repeating = 0;

    missing = (P / S + S) / 2;
    repeating = missing - S;
    vector<int> ans;
    ans.push_back(missing);
    ans.push_back(repeating);
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
/*
 *Time Complexity: O(N)

Space Complexity: O(1) As we are NOT USING EXTRA SPACE
*/