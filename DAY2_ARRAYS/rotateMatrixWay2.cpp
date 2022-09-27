/*
!Rotate Image by 90 degree
?Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
!https://takeuforward.org/data-structure/rotate-image-by-90-degree/
?Note: Rotate matrix 90 degrees anticlockwise

?Examples:

?Example 1:
*Input: [[1,2,3],[4,5,6],[7,8,9]]
*Output: [[7,4,1],[8,5,2],[9,6,3]]
!Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

?Example 2:
*Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
*Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
!Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix
*/
#include <bits/stdc++.h>
using namespace std;

void rotated(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) // j < i is needed becuase otherwise it will
        {
            // swap the elements again
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotated(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
!Solution 2: Optimized approach

!Intuition: By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

!Approach:

?Step1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)

?Step2: Reverse each row of the matrix.

*/
/*
*Time Complexity: O(N*N) + O(N*N).One O(N*N) for transposing the matrix and the other for reversing the matrix.

!Space Complexity: O(1).
*/