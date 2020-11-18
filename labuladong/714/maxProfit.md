# Best Time to Buy and Sell Stock with Transaction Fee
## Question
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Solution
### Analysis
1. dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)
2. dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### Code
```C++ []
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int count = prices.size();
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for (int i = 0; i < count; i++)
        {
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, temp - prices[i] - fee);
        }
        return dpi0;
    }
};