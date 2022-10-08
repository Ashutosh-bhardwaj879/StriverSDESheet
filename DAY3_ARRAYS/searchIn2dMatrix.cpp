/*
 *Search in a sorted 2D matrix
 //https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Given matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row
Example 1:

Input: matrix =
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]],

target = 3

Output: true

Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    //start from  the pointer to last elemnt of 0th row
    int i = 0;     // 0th row
    int j = cols - 1; // last column
    //everythign is sorted since we can use this algo
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
            j--;//move left
        }
        else
        {
            i++;//move down
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
    bool result = searchMatrix(matrix,target);
    cout << endl;
    cout << boolalpha << result << endl;
    return 0;
}