#  Best Time to Buy and Sell Stock IV
## Question
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

## Solution
### Analysis
1. dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
2. dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
3. if k>n/2 then (k=+infinity remove k)
4.     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
5.     dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
+ 时间复杂度：O(n*k)
+ 空间复杂度：O(n*k)
### Code
```C++ []
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n / 2) {
            return maxProfit_infinity(prices);
        }

        int dp[n][k+1][2];
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
        for (int j = 1; j < k+1; j++) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }

    int maxProfit_infinity(vector<int>& prices) {
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, dpi0 - prices[i]);
        }
        return dpi0;
    }
};