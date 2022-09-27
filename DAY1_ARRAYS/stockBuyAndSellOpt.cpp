/*
*Stock Buy And Sell
*https://takeuforward.org/data-structure/stock-buy-and-sell/
!Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

?You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
!Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and
sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1
is not allowed because you must buy before
you sell.

!Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are
done and the max profit = 0.
?Time complexity: O(n)

?Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
    return maxProfit;
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
/*
!Soltuion 2:Optimal solution

?Intuition: We will linearly travel the array. We can maintain a minimum from the starting of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.*/