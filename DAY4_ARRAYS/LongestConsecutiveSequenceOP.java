
/**
 * Longest Consecutive Sequence in an Array
Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Examples:

Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]

Output: 4

Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
 */
import java.util.HashSet;

class LongestConsecutiveSequenceOP {
    public static void main(String[] args) {
        int[] arr = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
        int lon = longestConsecutive(arr);
        System.out.println("The longest consecutive sequence is " + lon);
    }

    public static int longestConsecutive(int[] nums) {
        int longestStreak = 0;
        // 0 becuase [] for this case
        HashSet<Integer> hs = new HashSet<>();
        // filling whole array in hashset
        for (int num : nums) {
            hs.add(num);
        }
        // travrerisng wohle array
        for (int num : nums) {
            if (!hs.contains(num - 1)) {
                // it is 0 becuase every
                // we havent traversed in ti till now
                int currentStreak = 0;
                // now we will be traverisng with while loop
                int currentNum = num;
                // if set contains it , inc the count and inc te number too
                while (hs.contains(currentNum)) {
                    currentStreak += 1;
                    currentNum += 1;
                }
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
}
/**
 * Time Complexity: The time complexity of the above approach is O(N) because we
 * traverse each consecutive subsequence only once. (assuming hashset takes O(1)
 * to search)
 * Space Complexity: The space complexity of the above approach is O(N) because
 * we are maintaining a HashSet.
 */
/**
 * Solution 2: (Optimal Approach)
 * Approach: We will first push all are elements in the HashSet. Then we will
 * run a for loop and check for any number(x) if it is the starting number of
 * the consecutive sequence by checking if the HashSet contains (x-1) or not. If
 * ‘x’ is the starting number of the consecutive sequence we will keep searching
 * for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not
 * present in the HashSet. Using this we can calculate the length of the longest
 * consecutive subsequence.
 */