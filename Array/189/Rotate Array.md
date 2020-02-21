# 旋转数组
## 题目
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

## 题解
### 算法分析
1. 假设n = nums.size(), left = 0, sum = 0, len = INT_MAX
2. 先对k求余数：k = k % n
3. 先翻转数组：reverse(nums)
4. 再翻转前k个元素和后n-k个元素：reverse(nums[0], nums[k-1]), reverse(nums[k], nums[n-1])
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};