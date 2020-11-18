# 搜索插入位置
## 题目
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

## 题解
### 算法分析
1. 使用二分法，定义low=0，high = n - 1
2. 遍历数组直到low > high
3. 如果target <= nums[low] 返回low
4. 如果target > nums[high] 返回high + 1
5. 如果target == nums[high] 返回high
6. 定义mid = low + (high - low) / 2
7. 如果target == nums[mid] 返回mid
8. 如果target > nums[mid] low = mid + 1
9. 如果target < nums[mid] high = mid
10. 循环结束，返回low
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            if (target <= nums[low])
                return low;
            if (target > nums[high])
                return high + 1;
            else if (target == nums[high])
                return high;

            int mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};