# Partition Equal Subset Sum
## 题目
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

## 题解
### 解题思路
1. 使用动态规划,n=nums.size()
2. 求nums数组元素总和sum,sum=sum/2
3. 定义数组dp(sum+1)
4. 状态转移方程：dp[j] = dp[j] || dp[j-nums[i]]
3. 初始dp[0]=true,其他为false
4. 返回dp[sum]

### 复杂度分析
+ 时间复杂度：O(n*sum)
+ 空间复杂度：O(sum)
### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum / 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j-nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }

        return dp[sum];
    }
};