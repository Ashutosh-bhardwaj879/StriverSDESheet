
/*
!Program to generate Pascal’s Triangle
*Problem Statement: Given an integer N, return the first N rows of Pascal’s triangle.
!https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
?In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:
*/
import java.util.ArrayList;
import java.util.List;

class PrintPascaltriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> row = null;
        List<Integer> pre = null;
        // System.out.println(row.add(3));
        for (int i = 0; i < numRows; ++i) {
            row = new ArrayList<Integer>();
            for (int j = 0; j <= i; ++j)
                if (j == 0 || j == i)
                    row.add(1);
                else
                    row.add(pre.get(j - 1) + pre.get(j));
            pre = row;
            res.add(row);
        }
        return res;
    }
}

class printingPascalTriangle {
    public static void main(String[] args) {
        PrintPascaltriangle p = new PrintPascaltriangle();
        List<List<Integer>> l = new ArrayList<List<Integer>>();
        l = p.generate(10);
        print(l);
    }

    public static void print(List<List<Integer>> l) {
        System.out.println(l);
    }
}
/*
 * Time Complexity: We are creating a 2D array of size (numRows * numCols)
 * (where 1 <= numCols <= numRows), and we are traversing through each of the
 * cells to update it with its correct value, so Time Complexity = O(numRows2).
 *
  !Space Complexity: Since we are creating a 2D array, space complexity =
  ?O(numRows2).
 */