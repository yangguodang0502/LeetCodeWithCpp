#  寻找峰值
## 题目
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.

## 题解
### 算法分析
1. 初始条件：left = 0,right = n - 1,mid = left + right / 2
2. 终止条件：left == right
3. 向左查找：nums[mid] > nums[mid+1] -> right = mid
4. 向右查找：nums[mid] < nums[mid+1] -> left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid+1])
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