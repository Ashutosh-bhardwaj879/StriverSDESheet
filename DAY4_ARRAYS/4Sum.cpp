/**
 * https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
 * 4 Sum | Find Quads that add up to a target value
Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

Pre-req: Binary Search and 2-sum problem

Note:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
arr[a] + arr[b] + arr[c] + arr[d] == target
Example 1:

Input Format: arr[] = [1,0,-1,0,-2,2], target = 0

Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Explanation: We have to find unique quadruplets from
the array such that the sum of those elements is
equal to the target sum given that is 0.

The result obtained is such that the sum of the
quadruplets yields 0.
Example 2:

Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9

Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
*/
// three lopps , i,j,k and binary serach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> sv;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int remaining_target = (long long)target -
                                       (long long)nums[i] -
                                       (long long)nums[j] - (long long)nums[k];
                if (binary_search(nums.begin() + k + 1, nums.end(), remaining_target))
                {
                    vector<int> v;
                    v.emplace_back(nums[i]);
                    v.emplace_back(nums[j]);
                    v.emplace_back(nums[k]);
                    v.emplace_back(remaining_target);
                    // soritng the vector
                    sort(v.begin(), v.end());
                    // inserting vector into the set bcoz
                    // so that we dont have a duplicacy
                    sv.insert(v);
                }
            }
        }
    }
    // fillinf set into 2d array
    vector<vector<int>> result(sv.begin(), sv.end());
    return result;
}

int main()
{
    vector<int> v{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> sum = fourSum(v, target);
    cout << "The unique quadruplets are" << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}

/**
 * Time Complexity: O(N log N + N³ logN)
Reason: Sorting the array takes N log N and three nested loops will be taking N³ and for binary search, it takes another log N.
Space Complexity: O(1), (Generally the space complexity that is used to return the answer is ignored)
*/