/*
Grid Unique Paths | Count paths from left-top to the right bottom of a matrix
Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

Example 1:

Input Format: m = 2, n= 2
Output: 2
*/
// Recursive Solution
#include <bits/stdc++.h>
using namespace std;

int countPaths(int i, int j, int row, int column)
{
    //&& is needed here becuase
    // we should be pointed at last locations
    // at any cost
    if (i == row - 1 && j == column - 1)
    {
        return 1;
    }
    if (i >= row || j >= column)
    {
        return 0;
    }

    int downMove = countPaths(i + 1, j, row, column);
    int rightMove = countPaths(i, j + 1, row, column);
    return downMove + rightMove;
}

int uniquePaths(int row, int column)
{
    return countPaths(0, 0, row, column);
}

int main()
{
    int totalCount = uniquePaths(3, 7);
    cout << "The total number of Unique Paths are " << totalCount << endl;
    return 0;
}
/**
 * Time Complexity: The time comp[lexity of this recursive solution is exponential.

Space Complexity: As we are using stack space for recursion so the space complexity will also be exponential.
*/
/**
 * Approach: The problem states that we can either move rightward or downward direction. So we recursively try out all the possible combinations.

At first, we are at the (0,0) index let’s assume this state as (i,j). From here we can move towards the bottom as well as towards the right and we recursively move until we hit the base case.



2. At any point of time when the recursive call goes out of the matrix boundary (example: let’s assume m = 2, n= 2, and the current position of i and j is (2,0) which is out of matrix boundary), we’ll return zero because from here there are no possible paths beyond and that is the first base case.




3. Whenever the recursive call reaches the end we’ll return 1 because we have found one possible path to reach the end.




4. In the recursive tree what result we have got from the left transition and the right transition will sum it up and return the answer.



Code:
*/