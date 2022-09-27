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
void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> dummyRow(rows, -1);
    vector<int> dummyCol(cols, -1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                dummyRow[i] = 0;
                dummyCol[j] = 0;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //this  || consition is  used becuase if we use
            // && considiton then it will point to only the
            // exact elemnt not the other row,col elemnt of that
            // point
            if (dummyRow[i] == 0 || dummyCol[j] == 0)
            {
                matrix[i][j] = 0;
            }
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
!Time Complexity: O(N*M + N*M)

?Space Complexity: O(N)
*/

/*
? Solution 2:Better approach

!Intuition: Instead of traversing through each row and column, we can use dummy arrays to check if the particular row or column has an element 0 or not, which will improve the time complexity.

*Approach:Take two dummy array one of size of row and other of size of column.Now traverse through the array.If matrix[i][j]==0 then set dummy1[i]=0(for row) and dummy2[j]=0(for column).Now traverse through the array again and if dummy1[i]==0  || dummy2[j]==0 then arr[i][j]=0,else continue.
*/