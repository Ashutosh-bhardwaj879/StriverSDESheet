/*
 *Grid Unique Paths | Count paths from left-top to the right bottom of a matrix
Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.
*/
// DP Bottom Up Approach
/*
https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    // creating a 2d array
    int count[m][n];

    // filling whole 0'th column and 0'th row with 1
    // becuase for every movement we have 1 way
    for (int i = 0; i < m; i++)
    {
        count[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        count[0][j] = 1;
    }

    // now traversing in whole array
    int i, j;
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            count[i][j] = count[i - 1][j] + count[i][j - 1];
        }
    }

    return count[m - 1][n - 1];
}
int main()
{
    int totalCount = uniquePaths(3, 7);
    cout << "The total number of Unique Paths are " << totalCount << endl;
    return 0;
}