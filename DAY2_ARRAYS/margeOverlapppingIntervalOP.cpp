/*
!Merge Overlapping Sub-intervals
*Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

?Examples

?Example 1:

?Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

?Output: [[1,6],[8,10],[15,18]]

!Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.

?Example 2:

?Input: [[1,4],[4,5]]

?Output: [[1,5]]

*Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &interval)
{
    vector<vector<int>> mergedInterval;
    if (interval.size() == 0)
        return mergedInterval;

    sort(interval.begin(), interval.end());

    vector<int> tempInterval = interval[0];

    for (auto it : interval)
    {
        // if left elem of it < right elem of temp
        if (it[0] <= tempInterval[1])
        {
            // max of right elments in both the array lements

            tempInterval[1] = max(tempInterval[1], it[1]);
        }
        else
        {
            mergedInterval.push_back(tempInterval);
            /*
             *here tempInterval will point to the current element from it (not the next ELEMENT)
             *this also helps in tempInterval to get the last Element so that we can push it in line 54
             */
            tempInterval = it;
        }
    }
    //*this mergedInterval push will help in pushing the
    //*last elemnt vector
    mergedInterval.push_back(tempInterval);
    return mergedInterval;
}
void printRes(vector<vector<int>> &res)
{
    cout << "{ ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << ",";
        }
        cout << "}, ";
    }
    cout << "} ";
}
int main()
{
    // other tc {{1,2} {3,4} {5,6}};
    vector<vector<int>> arr;
    // arr = {{1, 3}, {2, 4}, {9, 9}};
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> res = mergeIntervals(arr);
    printRes(res);
    return 0;
}
/*
!Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.

!Space Complexity: O(N) to return the answer of the merged intervals.
*/