/**
 * https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
 * Two Sum : Check if a pair with given sum exists in Array
Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

Note: Assume that there is exactly one solution, and you are not allowed to use the same element twice. Example: If target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution
 */

// Solution 2 : Two - Pointer Approach
// Intuition : Think about,what if the array is sorted ? If the array is sorted, is it possible to reach a sum by traversing the array from both sides simultaneously ?

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int n, int target)
{
    // first make another vector
    // store whole nums vector to it , so that we dont change orign array

    // sort the temp array

    vector<int> res, store;
    store = nums;

    sort(store.begin(), store.end());

    int left = 0, right = nums.size() - 1;
    int n1, n2;
    // kindly note generally we do left <= rihgt
    //  here we wont don the same because
    // we are given that we cannot use same number again
    // so if we did left <= rihgt
    // we will check for left = right also
    while (left < right)
    {
        if (store[left] + store[right] == target)
        {
            /*we cannot di this here becuase it will store the array
            elemnts which are sorted , not the originlal one*/
            // res.emplace_back(left);
            // res.emplace_back(right);
            n1 = store[left];
            n2 = store[right];
            break;
        }
        else if (store[left] + store[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == n1)
        {
            res.emplace_back(i);
        }
        else if (nums[i] == n2)
        {
            res.emplace_back(i);
        }
    }
    return res;
}

void printVector(vector<int> v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> arr = {2, 8, 5, 4};
    int n = arr.size();
    int target = 9;
    vector<int> result = twoSum(arr, n, target);
    printVector(result, result.size());
    return 0;
}
/**
 * Time Complexity: O(NlogN)

Space Complexity: O(N)
*/