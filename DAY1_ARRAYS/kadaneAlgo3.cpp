/*
!https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
*Solution : 3 Optimal Solution: Kadane’s Algorithm

*Intuition: Basically this problem can be done in linear time complexity with Kadane’s algorithm along with that will also get the subarray which is giving the largest positive-sum.

*Time Complexity: O(N)
*Space Complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums, vector<int> &subarray)
{
    int insan = 0;
    int chor = INT_MIN;
    int startIndex = 0;
    int endIndex;

    for (int i = 0; i < nums.size(); i++)
    {
        insan += nums[i];
        if (insan > chor)
        {
            endIndex = i;
            chor = insan;
            subarray.clear();
            subarray.push_back(startIndex);
            subarray.push_back(endIndex);
        }
        if (insan < 0)
        {
            insan = 0;
            startIndex = i + 1;
        }
    }
    return chor;
}

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
/*
int max_so_far      = INT_MIN;//chor
int max_ending_here = 0;//insan
int max_element     = INT_MIN;

for (int i = 0; i < size; i++)
{
    insan = max(insan + array[i], 0);
    chor      = max(insan, chor);
    max_element     = max(max_element, array[i]);
}

if (max_so_far == 0)
  max_so_far = max_element;

printf("%d\n", max_so_far);
*/