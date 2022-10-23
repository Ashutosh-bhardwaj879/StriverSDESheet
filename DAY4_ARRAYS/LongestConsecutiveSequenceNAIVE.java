/**
 * Longest Consecutive Sequence in an Array
 * Problem Statement: You are given an array of ‘N’ integers. You need to find
 * the length of the longest sequence which contains the consecutive elements.
 *
 * https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
 * Examples:
 *
 * Example 1:
 *
 * Input: [100, 200, 1, 3, 2, 4]
 *
 * Output: 4
 *
 * Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
 *
 * Input: [3, 8, 5, 7, 6]
 *
 * Output: 4
 *
 * Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
 */
// naive approach
import java.util.Arrays;
class LongestConsecutiveSequenceNAIVE {
    public static void main(String[] args) {
        int[] arr = { 100, 200, 1, 2, 3, 4 };
        int lon = longestConsecutive(arr);
        System.out.println("The longest consecutive sequence is " + lon);
    }

    public static int longestConsecutive(int[] arr) {
        int n = arr.length;

        // sort thhe array things will be in sync then
        Arrays.sort(arr);
        // traverse in whole array
        int prev = arr[0];
        int ans = 1;
        int currentStreak = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == prev + 1) {
                currentStreak++;
            } else if (arr[i] != prev) {
                currentStreak = 1;
            }
            prev = arr[i];
            ans = Math.max(currentStreak, ans);
        }
        return ans;
    }
}
/**
 * Time Complexity: We are first sorting the array which will take O(N * log(N))
 * time and then we are running a for loop which will take O(N) time. Hence, the
 * overall time complexity will be O(N * log(N)).
 * Space Complexity: The space complexity for the above approach is O(1) because
 * we are not using any auxiliary space
 */