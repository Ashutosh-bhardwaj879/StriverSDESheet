/*
 Search in a row wise and column wise sorted matrix
Difficulty Level : Medium
Last Updated : 19 Sep, 2022
Read
Discuss

Given an n x n matrix and an integer x, find the position of x in the matrix if it is present. Otherwise, print “Element not found”. Every row and column of the matrix is sorted in increasing order. The designed algorithm should have linear time complexity
Input: mat[4][4] = { {10, 20, 30, 40},  x = 29
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                             {32, 33, 39, 50}}

Output: Found at (2, 1)
Explanation: Element at (2,1) is 29

Input : mat[4][4] = { {10, 20, 30, 40},   x = 100
                                {15, 25, 35, 45},
                               {27, 29, 37, 48},
                              {32, 33, 39, 50}};

Output: Element not found
Explanation: Element 100 does not exist in the matrix
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    // start from  the pointer to last elemnt of 0th row
    int i = 0;        // 0th row
    int j = cols - 1; // last column
    // everythign is sorted since we can use this algo
    while (i < rows && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            cout << target << " found at (row,column)"
                 << " (" << i << "," << j << ")";
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j--; // move left
        }
        else
        {
            i++; // move down
        }
    }
    return false;
}

int main()
{
    // int n = 3;
    // int m = 4;
    // vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<vector<int>> matrix{
        {10, 20, 30, 40},
        {11, 21, 36, 43},
        {25, 29, 39, 50},
        {50, 60, 70, 80}};
    int target = 36;
    bool result = searchMatrix(matrix, target);
    cout << endl;
    cout << boolalpha << result << endl;
    return 0;
}
/**
 * https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
 * Time Complexity: O(N), Only one traversal is needed, i.e, i from 0 to n and j from n-1 to 0 with at most 2*N steps. The above approach will also work for the M x N matrix (not only for N x N). Complexity would be O(M + N)
Auxiliary Space: O(1), No extra space is required
*/