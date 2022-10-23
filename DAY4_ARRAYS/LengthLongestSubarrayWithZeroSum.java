/*
 * Length of the longest subarray with zero Sum
 * Problem Statement: Given an array containing both positive and negative
 * integers, we have to find the length of the longest subarray with the sum of
 * all elements equal to zero.
 *
 * Example 1:
 *
 * Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
 *
 * Result: 5
 *
 * Explanation: The following subarrays sum to zero:
 * {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
 * Since we require the length of the longest subarray, our answer is 5!
 * Example 2:
 *
 * Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
 *
 * Result: 8
 *
 * Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8,
 * 1, 7, 4, -10}
 * Length of longest subarray = 8
 * Example 3:
 *
 * Input Format: N = 3, array[] = {1, 0, -5}
 *
 * Result: 1
 *
 * Subarray : {0}
 * Length of longest subarray = 1
 * Example 4:
 *
 * Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
 *
 * Result: 0
 *
 * Subarray: There is no subarray that sums to zero
 */
class LengthLongestSubarrayZeroSumNAIVE {
    public static void main(String[] args) {
        int[] a = { 6, -2, 2, -8, 1, 7, 4, -10 };
        System.out.println(solve(a));
    }

    public static int solve(int[] a) {
        int n = a.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum = sum + a[j];
                if (sum == 0) {
                    // j-i+1 is used becuase
                    // we are waiting for sum == 0
                    // TC = {0}
                    // here 0-0+1 is needed becuase it is 1 element
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
}
/*
 * Time Complexity:O(N^2) as we have two loops for traversal
 *
 * Space Complexity : O(1) as we aren’t using any extra space.
 */