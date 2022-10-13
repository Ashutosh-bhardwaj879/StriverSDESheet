/*
 *Grid Unique Paths | Count paths from left-top to the right bottom of a matrix
Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.
*/
// DP Top Down
/*
https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // dp[1][1]=1;
        int num = countPaths(0, 0, m, n, dp);
        // if (m == 1 && n == 1)
        //     return num;
        return num;
        // return dp[0][0];
    }
};
int main()
{
    Solution obj;
    int totalCount = obj.uniquePaths(2, 2);
    cout << "The total number of Unique Paths are " << totalCount << endl;
}
/**
 * https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
 */

/**
 *
 * Time Complexity: O(M*N) – Due to nested for loops.
Auxiliary Space : O(M*N) – We have used a 2D array of size MxN.
*/