
/*
 *https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/
 */
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
import java.util.*;

class LenLonSSWORepCharOP {
    public static void main(String[] args) {
        String str = "takeUforward";
        System.out.println("The length of the longest substring without repeating characters is " + solve(str));
    }

    public static int solve(String str) {
        int n = str.length();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        HashMap<Character, Integer> mp = new HashMap<>();
        while (right < n) {
            if (mp.containsKey(str.charAt(right))) {
                left = Math.max(left, mp.get(str.charAt(right)) + 1);
            }
            mp.put(str.charAt(right), right);
            // update the last seen of evry duplicate and non duplicat
            // elemnt
            maxLen = Math.max(maxLen, right - left + 1);
            right++;// this should be at last becuase pehle
            // kiya hota to maxlen bigad jaata
        }
        return maxLen;
    }
}
/*
 * Time Complexity: O( N )
 *
 * Space Complexity: O(N) where N represents the size of HashSet where we are
 * storing our elements
 */
/*
 * Solution 3: Optimised Approach 2
 *
 * Approach: In this approach, we will make a map that will take care of
 * counting the elements and maintaining the frequency of each and every element
 * as a unity by taking the latest index of every element.
 */