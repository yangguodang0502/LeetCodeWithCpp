#  二分查找
## 题目
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].

## 题解
### 算法分析
1. 使用二分查找，定义左右区间索引，初始化为数组首尾位置
2. 遍历数组知道右索引大于等于左索引，取中间索引=左右索引的和的一半
3. 如果中间索引对应的元素等于目标元素，返回中间索引
4. 否则如果小于目标元素，则左边索引=中间索引+1
5. 否则右边索引=中间索引-1
6. 遍历结束返回-1
### 复杂度分析
+ 时间复杂度：O(logn)，n为数组个数
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (rightIndex >= leftIndex)
        {
            int midIndex = (leftIndex + rightIndex) / 2;
            if (nums[midIndex] == target)
                return midIndex;
            else if (nums[midIndex] < target)
                leftIndex = midIndex + 1;
            else
                rightIndex = midIndex - 1;
        }
        
        return -1;
    }
};