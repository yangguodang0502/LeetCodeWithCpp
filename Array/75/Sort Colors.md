# 颜色分类
## 题目
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

## 题解
### 算法分析
1. 初始化0的右边界为p0=0，2的左边界为p2=n-1
2. 初始化cur=0,遍历数组直到cur>p2
3. 如果nums[cur]==0，交换nums[cur]和nums[p0]，cur、p0右移
4. 如果nums[cur]==2，交换nums[cur]和nums[p2]，p2左移
5. 否则cur右移
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0;
        int p0 = 0;
        int p2 = nums.size() - 1;
        while (cur <= p2)
        {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[p0++]);
            }
            else if (nums[cur] == 2) {
                swap(nums[cur], nums[p2--]);
            }
            else {
                cur++;
            }
        }        
    }
};