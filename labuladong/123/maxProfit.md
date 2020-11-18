#  Best Time to Buy and Sell Stock III
## Question
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

## Solution
### Analysis
1. dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
2. dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
3. dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
4. dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])
               = max(dp[i-1][1][1], - prices[i])
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### Code
```C++ []
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpi10 = 0;
        int dpi11 = INT_MIN;
        int dpi20 = 0;
        int dpi21 = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            dpi20 = max(dpi20, dpi21 + prices[i]);
            dpi21 = max(dpi21, dpi10 - prices[i]);
            dpi10 = max(dpi10, dpi11 + prices[i]);
            dpi11 = max(dpi11, -prices[i]);
        }        
        return dpi20;
    }
};