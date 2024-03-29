# Coin Change 2
## 题目
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
0 <= amount <= 5000

## 题解
### 解题思路
1. 使用动态规划,n=coins.size()
2. 定义数组dp(amount+1)
3. 状态转移方程：dp[j] = dp[j] + dp[j-coins[i]]
4. 初始dp[0]=1,其他为0
5. 返回dp[amount]

### 复杂度分析
+ 时间复杂度：O(n*amount)
+ 空间复杂度：O(amount)
### 代码

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j-coins[i] >= 0) {
                    dp[j] = dp[j] + dp[j-coins[i]];
                }
            }
        }

        return dp[amount];
    }
};