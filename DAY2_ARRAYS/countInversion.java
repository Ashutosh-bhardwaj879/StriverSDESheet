
/*
 * https://www.youtube.com/watch?v=uojx--MK_n0
 * https://takeuforward.org/data-structure/count-inversions-in-an-array/
 * Count inversions in an array
 * Problem Statement: Given an array of N integers, count the inversion of the
 * array (using merge-sort).
 *
 * What is an inversion of an array? Definition: for all i & j < size of array,
 * if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
 *
 * Example 1:
 *
 * Input Format: N = 5, array[] = {1,2,3,4,5}
 *
 * Result: 0
 *
 * Explanation: we have a sorted array and the sorted array
 * has 0 inversions as for i < j you will never find a pair
 * such that A[j] < A[i]. More clear example: 2 has index 1
 * and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
 * inversion.
 * Example 2:
 *
 * Input Format: N = 5, array[] = {5,4,3,2,1}
 *
 * Result: 10
 *
 * Explanation: we have a reverse sorted array and we will
 * get the maximum inversions as for i < j we will always
 * find a pair such that A[j] < A[i].
 * Example: 5 has index 0 and 3 has index 2 now (5,3) pair
 * is inversion as 0 < 2 and 5 > 3 which will satisfy out
 * conditions and for reverse sorted array we will get
 * maximum inversions and that is (n)*(n-1) / 2.
 *
 * For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
 * ExampleInput Format: N = 5, array[] = {5,3,2,1,4}
 *
 * Result: 7
 *
 * Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
 * (3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and
 * (1,4) as both are not satisfy our condition.
 */
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class CountInversion {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Logger logger = Logger.getLogger(CountInversion.class.getName());
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        mergeSort(arr, 0, n - 1);
        logger.log(Level.INFO, "Count {0}", count);
        scn.close();
    }

    protected static int count = 0;

    public static int[] mergeSort(int[] arr, int lo, int hi) {
        if (lo == hi) {
            int[] baseArray = new int[1];
            baseArray[0] = arr[lo];
            return baseArray;
        }
        int mid = (lo + hi) / 2;
        int[] left = mergeSort(arr, lo, mid);
        int[] right = mergeSort(arr, mid + 1, hi);
        // int[] merged =
        return merge2SortedArrays(left, right);
    }

    public static int[] merge2SortedArrays(int[] left, int[] right) {
        int i = 0;
        int j = 0;
        int k = 0;
        int[] merged = new int[left.length + right.length];
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                merged[k++] = left[i++];
            } else {
                count += (left.length - i);
                merged[k++] = right[j++];
            }
        }
        while (i < left.length) {
            merged[k++] = left[i++];
        }
        while (j < right.length) {
            merged[k++] = right[j++];
        }
        return merged;
    }
}