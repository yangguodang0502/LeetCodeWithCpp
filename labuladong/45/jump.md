# Jump Game II
## 题目
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 105

## 题解
### 解题思路
1. 使用动态规划,n=nums.size()
2. 定义farthest=0，end=0，jumps=0
3. 遍历nums，i=[0,n-1)，farthest=max(farthest, i+nums[i])
4. 如果end=i，则jumps++，end=farthest
5. 遍历结束，返回jumps

### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int end = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};