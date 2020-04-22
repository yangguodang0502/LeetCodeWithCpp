#  在排序数组中查找元素的第一个和最后一个位置
## 题目
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

## 题解
### 算法分析
1. 初始条件：left = 0,right = n,mid = left + right / 2,isLeft表示查找的是左下标还是右下标
2. 终止条件：left == right
3. 向左查找：nums[mid] > target || (isLeft && nums[mid] == target) -> right = mid
4. 向右查找：left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange {-1, -1};
        
        int leftIndex = findIndex(nums, target, true);
        if (leftIndex == nums.size() || nums[leftIndex] != target)
        {
            return targetRange;
        }

        targetRange[0] = leftIndex;
        targetRange[1] = findIndex(nums, target, false) - 1;

        return targetRange;
    }

    int findIndex(vector<int>& nums, int target, bool isLeft)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (isLeft && nums[mid] == target))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
};