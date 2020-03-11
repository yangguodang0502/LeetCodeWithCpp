# 目标和
## 题目
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

## 题解
### 算法分析
1. 使用动态规划，转化为01背包问题
2. 假设sum表示nums总和，当S > sum时无解，返回0
3. 假设sumP表示正数和，sumN表示负数和
4. 则由sumP - sumN = S, sump + sumN = sum可得2*sumP = S + sum
5. 所以当(S + sum) % 2 != 0时无解，返回0
6. sumP = (S+sum)/2
7. 定义数组dp[sumP+1]用于存储正数和为sumP的结果, dp[0] = 1
8. 遍历nums, num : nums
9. 遍历dp, i = sumP : num : --
10. dp[i] += dp[i - num]
11. 最后返回dp[sumP]
### 复杂度分析
+ 时间复杂度：O(n*sumP), n = nums.size()
+ 空间复杂度：O(sumP)
### 源码
```C++ []
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;

        for (const auto &num : nums)
            sum += num;
        
        if (S > sum)
            return 0;
        
        S += sum;
        if (S % 2 != 0)
            return 0;

        int sumP = S / 2;
        vector<int> dp(sumP+1, 0);
        dp[0] = 1;

        for (const auto &num : nums)
        {
            for (int i = sumP; i >= num; i--)
            {
                dp[i] += dp[i - num];
            }            
        }
        
        return dp[sumP];
    }
};