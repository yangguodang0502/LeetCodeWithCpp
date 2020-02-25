# 移动零
## 题目
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

## 题解
### 算法分析
1. 假设n = nums.size()
2. 遍历nums，i = 0 : n - 1
3. 找到第一个nums[i] == 0
4. 遍历nums, j = i + 1 ： n-1
5. 如果nums[j] != 0, 交换nums[i]和nums[j]
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return;
        
        int i = 0;
        
        while (i < n)
        {
            if (nums[i] == 0)
            {
                int  j = i + 1;
                while (j < n)
                {
                    if (nums[j] != 0)
                    {
                        swap(nums[i], nums[j]);
                        ++i;
                    }

                    ++j;
                }
                return;
            }

            ++i;
        }
    }
};