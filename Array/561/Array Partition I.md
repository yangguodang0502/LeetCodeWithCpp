# 数组拆分 I
## 题目
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

## 题解
### 算法分析
1. 公式：sort(nums), sum += nums[i], i = 0 : n - 2 : 2
2. 先对nums进行从小到大排序，计算sum = nums[0] + nums[2] + ... + nums[n-2]
### 复杂度分析
+ 时间复杂度：O(nlog(n))，n为nums长度，nlog(n)为排序消耗时间
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }

        return sum;
    }
};