
/*
 * Length of Longest Substring without any Repeating Character
 * ?Problem Statement: Given a String, find the length of longest substring
 * without any repeating character.
 *
 * !Examples:
 *
 * !Example 1:
 *
 * !Input: s = ”abcabcbb”
 *https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/
 * !Output: 3
 *
 * !Explanation: The answer is abc with length of 3.
 *
 * !Example 2:
 *
 * !Input: s = ”bbbbb”
 *
 * !Output: 1
 *
 * Explanation: The answer is b with length of 1 units.
 */
/*
 *NAIVE APPROACH
 ? using HashSet
 */
import java.util.*;

class LongestSubstringWithoutRepeat {
    public static void main(String[] args) {
        String str = "takeUforward";
        System.out.println("The length of the longest substring without repeating characters is " + solve(str));
    }

    public static int solve(String str) {
        int n = str.length();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            Set<Character> set = new HashSet<>();
            for (int j = i; j < n; j++) {
                if (set.contains(str.charAt(j))) {
                    // means that the ch is already present in set
                    // since it is already present
                    // we encountered a duplicate
                    // break the loop is best becuase usse aage bhi badhe to koi fayda nahi hoga
                    ans = Math.max(ans, j - i);
                    break;
                }
                set.add(str.charAt(j));
            }
        }
        return ans;
    }
}

/*
 * Time Complexity: O( N2 )
 *
 * Space Complexity: O(N) where N is the size of HashSet taken for storing the
 * elements
 */
/*
 * ?Solution 1: Brute force Approach
 *
 * Approach: This approach consists of taking the two loops one for traversing
 * the string and another loop – nested loop for finding different substrings
 * and after that, we will check for all substrings one by one and check for
 * each and every element if the element is not found then we will store that
 * element in HashSet otherwise we will break from the loop and count it.
 */