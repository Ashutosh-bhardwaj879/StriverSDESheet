/*
*https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
!Input Format: N = 5

!Result:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

!Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.
*/
#include <bits/stdc++.h>
using namespace std;

class GeneratePascalTriangle
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);         // resising array at every level
            r[i][0] = r[i][i] = 1;      // setting its 0th and last elemnt 1 always
            for (int j = 1; j < i; j++) // traversing from >0 <i rows , <i is double less than last elem becuase in abpve loop it is smaller than n
            {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        return r;
    }
};
void printPascalTriangle(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    GeneratePascalTriangle g;
    vector<vector<int>> pascalTriangle = g.generate(5);
    printPascalTriangle(pascalTriangle);
    return 0;
}