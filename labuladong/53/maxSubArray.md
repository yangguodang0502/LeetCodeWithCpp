# Maximum Subarray
## 题目
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105

## 题解
### 解题思路
1. 使用动态规划
2. 状态转移方程：dp[i]=max(nums[i], nums[i] + dp[i-1])，
    dp[i]要么与前面形成更大数组，要么自己作为一个子数组
3. 初始dp[0]=nums[0]
4. 定义res=dp[0]，
5. 遍历nums，计算res=max(res, dp[i])
6. 返回res

### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int dp0 = nums[0];
        int dp1;
        int res = dp0;
        for (int i = 1; i < n; i++) {
            dp1 = max(nums[i], nums[i] + dp0);
            dp0 = dp1;
            res = max(res, dp1);
        }
        return res;
    }
};