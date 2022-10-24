
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
 * https://takeuforward.org/data-structure/length-of-longest-substring-without-
 * any-repeating-character/
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
//Sdcond way little optimized
//hashset
import java.util.*;

class LengthOfLongestSubstringWithoutRepeatingCharacter {
    public static void main(String[] args) {
        String str = "abcabcbb";
        System.out.println("The length of the longest substring without repeating characters is " + solve(str));
    }

    public static int solve(String str) {
        int n = str.length();
        int l = 0;
        int res = 0;
        Set<Character> st = new HashSet<>();
        for (int r = 0; r < n; r++) {
            if (st.contains(str.charAt(r))) {
                while (l < r && st.contains(str.charAt(r))) {
                    st.remove(str.charAt(l));
                    l++;
                }
            }
            st.add(str.charAt(r));
            res = Math.max(res, r - l + 1);
        }
        return res;
    }
}
/*
 * Time Complexity: O( 2*N ) (sometimes left and right both have to travel
 * complete array)
 *
 * Space Complexity: O(N) where N is the size of HashSet taken for storing the
 * elements
 */
/*
 * Solution 2: Optimised Approach 1
 *
 * Approach: We will have two pointers left and right. Pointer ‘left’ is used
 * for maintaining the starting point of substring while ‘right’ will maintain
 * the endpoint of the substring.’ right’ pointer will move forward and check
 * for the duplicate occurrence of the current element if found then ‘left’
 * pointer will be shifted ahead so as to delete the duplicate elements.
 *
 *
 */