# 最大连续1的个数
## 题目
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

## 题解
### 算法分析
1. 假设n = nums.size(), count = 0, maxCount = 0,
2. 遍历nums, i = 0 : n - 1
3. if nums[i] == 1 then ++count 
   else if count > maxCount then maxCount = count
        count = 0
4. 遍历结束再做一次判断：if count > maxCount then maxCount = count
5. return maxCount
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                ++count;
            }
            else
            {
                if (count > maxCount)
                {
                    maxCount = count;
                }

                count = 0;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
        }

        return maxCount;
    }
};