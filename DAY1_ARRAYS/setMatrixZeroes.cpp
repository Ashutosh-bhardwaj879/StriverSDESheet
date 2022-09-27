/*
? Problem Statement : Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
 ! https://takeuforward.org/data-structure/set-matrix-zero/
 ! https://www.geeksforgeeks.org/passing-vector-function-cpp/
 ! https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
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
// int mat[3][3];
/*
! WE pass vector by reference otherwise the changes won't be seen
! and the time will be hige becuase everytime it makae a copies

*/
void printVMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void setVZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                /*
                * Below code will help us to trvaerse the same elemnets
                * correspinding rows and columns
                */
                int ind = i - 1;
                while (ind >= 0)
                {
                    if (matrix[ind][j] != 0)
                    {
                        matrix[ind][j] = -1;
                    }
                    ind--;
                }
                ind = i + 1;
                while (ind < rows)
                {
                    if (matrix[ind][j] != 0)
                    {
                        matrix[ind][j] = -1;
                    }
                    ind++;
                }
                ind = j - 1;
                while (ind >= 0)
                {
                    if (matrix[i][ind] != 0)
                    {
                        matrix[i][ind] = -1;
                    }
                    ind--;
                }
                ind = j + 1;
                while (ind < cols)
                {
                    if (matrix[i][ind] != 0)
                    {
                        matrix[i][ind] = -1;
                    }
                    ind++;
                }
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] <= 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix;
    matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    int mat[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int rows = sizeof mat / sizeof mat[0];    // 3 rows
    int column = sizeof mat[0] / sizeof(int); // 3 cols
    cout << "Before " << endl;
    // printMatrix(mat, rows, column);
    printVMatrix(matrix);
    // setZeroes(mat, rows, column);
    setVZeroes(matrix);
    cout << "After " << endl;
    // printMatrix(mat, rows, column);
    printVMatrix(matrix);
}
/*
* Time Complexity:O((N*M)*(N + M)). O(N*M) for traversing through each element and (N+M)for traversing to row and column of elements having value 0.

* Space Complexity:O(1)
*/
// void printMatrix(int mat[][3], int rows, int column)
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// void setZeroes(int mat[][3], int rows, int column)
// {

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             if (mat[i][j] == 0)
//             {

//                 int ind = i - 1;

//                 while (ind >= 0)
//                 {
//                     if (mat[ind][j] != 0)
//                     {
//                         mat[ind][j] = -1;
//                     }
//                     ind--;
//                 }

//                 ind = i + 1;
//                 while (ind < rows)
//                 {
//                     if (mat[ind][j] != 0)
//                     {
//                         mat[ind][j] = -1;
//                     }
//                     ind++;
//                 }
//                 ind = j - 1;
//                 while (ind >= 0)
//                 {
//                     if (mat[i][ind] != 0)
//                     {
//                         mat[i][ind] = -1;
//                     }
//                     ind--;
//                 }
//                 ind = j + 1;
//                 while (ind < column)
//                 {
//                     if (mat[i][ind] != 0)
//                     {
//                         mat[i][ind] = -1;
//                     }
//                     ind++;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             if (mat[i][j] <= 0)
//             {
//                 mat[i][j] = 0;
//             }
//         }
//     }
// }

