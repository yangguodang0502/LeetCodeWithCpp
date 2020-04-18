#  搜索旋转排序数组
## 题目
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

## 题解
### 算法分析
1. 初始条件：left = 0,right = n - 1,mid = (left + right) / 2
2. 终止条件：left > right or target == nums[left] or target == nums[right] or target == nums[mid]
3. 向左查找：nums[left] < nums[mid] and target < nums[mid] && target > nums[left] -> left = left +1, right = mid - 1
4. 向右查找：nums[mid] > nums[right] and target > nums[mid] && target < nums[right] -> left = mid +1, right = right - 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRecursive(nums, target, 0, nums.size() - 1);
    }

    int searchRecursive(vector<int>& nums, int target, int left, int right)
    {
        if (left > right)
            return -1;
        
        if (target == nums[left])
            return left;
        
        if (target == nums[right])
            return right;
        
        int mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;

        if (nums[left] < nums[mid])
        {
            if (target < nums[mid] && target > nums[left])
            {
                return searchRecursive(nums, target, left + 1, mid - 1);
            }
            else
            {
                return searchRecursive(nums, target, mid + 1, right - 1);
            }            
        }
        else
        {
            if (target > nums[mid] && target < nums[right])
            {
                return searchRecursive(nums, target, mid + 1, right - 1);
            }
            else
            {
                return searchRecursive(nums, target, left + 1, mid - 1);
            }  
        }        
    }
};