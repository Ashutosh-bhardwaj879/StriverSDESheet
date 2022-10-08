/*
Search in a sorted 2D matrix
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
Example 2:

Input: matrix =
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]],

target = 13

Output: false

Explanation: As the given integer(target) does not exist in the given 2D matrix, the function has returned false.
https:// takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrixLC(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = 0;
    int high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        //[mid / m][mid % m]
        // this will help in find the index of mid
        if (matrix[mid / cols][mid % cols] == target)
        {
            cout << target << " found at (row,column)"
                 << " (" << mid / cols << "," << mid % cols << ")";
            return true;
        }
        else if (target > matrix[mid / cols][mid % cols])
        {
            // means target is ont he right side
            low = mid + 1;
        }
        else
        {
            // means target is on the left side
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 7;
    bool result = searchMatrixLC(matrix, target);
    cout << endl
         << boolalpha << result << endl;
    return 0;
}
/*
Time complexity: O(log(m*n))

Space complexity: O(1)
*/