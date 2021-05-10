# Jump Game
## 题目
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105

## 题解
### 解题思路
1. 使用动态规划,n=nums.size()
2. 定义farthest=0
3. 遍历nums，i=[0,n-1)，farthest=max(farthest, i+nums[i])
4. 如果farthest<=i，返回false
5. 遍历结束，返回farthest>=n-1

### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if (farthest <= i) {
                return false;
            }
        }
        return farthest >= n-1;
    }
};