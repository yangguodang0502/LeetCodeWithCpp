#  寻找旋转排序数组中的最小值
## 题目
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

## 题解
### 算法分析
1. 初始条件：left = 0,right = n - 1,mid = left + right / 2
2. 终止条件：left == right
3. 向左查找：nums[mid] < nums[right] -> right = mid
4. 向右查找：nums[mid] >= nums[right] -> left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return nums[left];
    }
};