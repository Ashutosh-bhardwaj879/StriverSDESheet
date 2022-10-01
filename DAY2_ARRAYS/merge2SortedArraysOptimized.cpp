/*
*Merge two Sorted Arrays Without Extra Space

!Problem statement : Given two sorted arrays arr1[] and arr2[] of sizes n and m in non - decreasing order.Merge them in sorted order.Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
Examples :
*Example 1 :
?Input : n = 4, arr1[] = [1 4 8 10] m = 5, arr2[] = [2 3 9]
?Output : arr1[] = [1 2 3 4] arr2[] = [8 9 10]
?Explanation : After merging the two non-decreasing arrays,we get, 1, 2, 3, 4, 8, 9, 10.

*Example2 :
?Input : n = 4, arr1[] = [1 3 5 7] m = 5, arr2[] = [0 2 6 8 9]
?Output : arr1[] = [0 1 2 3] arr2[] = [5 6 7 8 9]
?Explanation : After merging the two non - decreasing arrays,
?we get, 0 1 2 3 5 6 7 8 9.
*/
#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i, k;
    for (i = 0; i < n; i++)
    {
        // If arr1[i] is greater than arr2[0] then swap,
        // kindly note we are sorting the arr2 everytimg in next
        // loop, so choosing arr2[0] is fine bcoz its sorted

        // take first element from arr1
        // compare it with first element of second array
        // if condition match, then swap
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
        }

        // then sort the second array
        // put the element in its correct position
        // so that next cycle can swap elements correctly
        int first = arr2[0];
        for (k = 1; k < m && arr2[k] < first; k++)
        {
            arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
    }
}
int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};

    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}
/*
*Time complexity: O(n*m)

*Space Complexity: O(1)
*/