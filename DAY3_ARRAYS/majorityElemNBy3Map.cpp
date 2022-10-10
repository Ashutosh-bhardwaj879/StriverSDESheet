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
// Solution 2: Better Solution

// Approach : Traverse the whole array and store the count of every element in a map.After that traverse through the map and whenever you find the count of an element greater than N / 3 times, store that element in your answer.

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElemNBy3Map(vector<int> &arr, int n)
{
    vector<int> ans;
    unordered_map<int, int> umap;
    // this will count the freq of each element
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    // umap ( K --> V )pair
    for (auto it : umap)
    {
        if (it.second > n / 3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    int n = arr.size();
    vector<int> majority = majorityElemNBy3Map(arr, n);
    for (auto it : majority)
    {
        cout << it << " ";
    }
    return 0;
}
/*
Time Complexity: O(n)

Space Complexity: O(n)
*/