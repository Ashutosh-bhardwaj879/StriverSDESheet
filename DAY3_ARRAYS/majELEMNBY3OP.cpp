/**https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
 *Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

Example 1:

Input: N = 5, array[] = {1,2,2,3,2}

Ouput: 2

Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
Example 2:

Input:  N = 6, array[] = {11,33,33,11,33,11}

Output: 11 33

Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.
 */
// Solution 3: Optimal Solution (Extended Boyer Moore’s Voting Algorithm)
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElemNBy3(vector<int> &arr, int n)
{
    // we will take count 2 variable becuase we know in an array >N/3 elemnt count can be 2
    // eg{11,11,11,33,33,33}, count can be two
    int count1 = 0;
    int count2 = 0;
    int nums1 = -1;
    int nums2 = -1;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == nums1)
        {
            count1++;
        }
        else if (arr[i] == nums2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            nums1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            nums2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == nums1)
        {
            count1++;
        }
        else if (arr[i] == nums2)
        {
            count2++;
        }
    }
    if (count1 > n / 3)
    {
        ans.push_back(nums1);
    }
    if (count2 > n / 3)
    {
        ans.push_back(nums2);
    }
    return ans;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    int n = arr.size();
    vector<int> majority;
    majority = majorityElemNBy3(arr, n);
    for (auto it : majority)
    {
        cout << it << " ";
    }
    return 0;
}
/**
 * Time Complexity: O(n)

Space Complexity: O(1)
*/