/*
? Problem Statement : Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
 ! https://takeuforward.org/data-structure/set-matrix-zero/
 ! https://www.geeksforgeeks.org/passing-vector-function-cpp/
 ! https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
 ! https://www.youtube.com/watch?v=zgaOU5aInOc
* Examples :

* Examples 1 :

* Input : matrix = [ [ 1, 1, 1 ], [ 1, 0, 1 ], [ 1, 1, 1 ] ]

* Output : [ [ 1, 0, 1 ], [ 0, 0, 0 ], [ 1, 0, 1 ] ]

* Explanation : Since matrix[2][2] = 0.Therfore the 2nd column and 2nd row wil be set to 0.

* Input : matrix = [ [ 0, 1, 2, 0 ], [ 3, 4, 5, 2 ], [ 1, 3, 1, 5 ] ]

* Output : [ [ 0, 0, 0, 0 ], [ 0, 4, 5, 0 ], [ 0, 3, 1, 0 ] ]

* Explanation : Since matrix[0][0] = 0 and matrix[0][3] = 0.
* Therefore 1st row,1st column and 4th column will be set to 0
*/
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // rows
    int m = matrix[0].size(); // cols
    bool row = false;
    bool col = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            col = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            row = true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 1; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (row)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
void printMatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> arr;
    arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    printMatrix(arr);
    setZeroes(arr);
    printMatrix(arr);
    return 0;
}
/*
!Time Complexity: O(2*(N*M)), as we are traversing two times in a matrix,

*Space Complexity: O(1).
*/