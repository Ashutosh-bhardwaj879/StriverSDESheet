/*
!Rotate Image by 90 degree
?Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

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

vector<vector<int>> rotateBy90(vector<vector<int>> &matrix)
{
    // it is a square matrx so rows == column == matrix.size()
    int n = matrix.size();
    vector<vector<int>> rotatedMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //first row == last col and so on
            //so col will be constant,row will change one by one
            // 1 2 3 ==> 1
            //           2
            //           3
            //we see here row is increasing but col is constant
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotatedMatrix;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated = rotateBy90(arr);

    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[0].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
 *Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so
 */
/*
!Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
?Space Complexity: O(N*N) to copy it into some other matrix.
*/