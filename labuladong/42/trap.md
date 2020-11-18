#  接雨水
## 题目
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

## 题解
### 算法分析
1. 使用双指针，定义left=0,right=n-1,lMax=rMax=res=0
2. 遍历指针left<right,lMax=max(lMax, height[left]),rMax=max(rMax, height[right])
3. 如果lMax<rMax,res加上lMax与height[left]的差,left往右前进
4. 否则res加上rMax与height[right]的差，right往左前进
5. 遍历结束返回res
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;
        
        int left = 0;
        int right = n-1;
        int lMax = 0;
        int rMax = 0;
        int res =0;

        while (left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);
            if (lMax < rMax) {
                res += lMax - height[left];
                left++;
            } else {
                res += rMax - height[right];
                right--;
            }
        }
        
        return res;
    }
};