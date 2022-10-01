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
    int arr3[n + m];
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
    sort(arr3, arr3 + n + m);

    k = 0;
    i = 0;
    j = 0;
    while (i < n)
    {
        arr1[i++] = arr3[k++];
    }
    while (j < m)
    {
        arr2[j++] = arr3[k++];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     arr1[i] = arr3[k++];
    // }
    // for (int j = 0; j < m; j++)
    // {
    //     arr2[j] = arr3[k++];
    // }
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
}
/*
*Time complexity: O(n*log(n))+O(n)+O(n)

*Space Complexity: O(n)
*/