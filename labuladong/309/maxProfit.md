# Best Time to Buy and Sell Stock with Cooldown
## Question
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

## Solution
### Analysis
1. dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
2. dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### Code
```C++ []
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        int dpPre0 = 0;
        for (int i = 0; i < count; i++)
        {
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, dpPre0 - prices[i]);
            dpPre0 = temp;
        }
        return dpi0;
    }
};