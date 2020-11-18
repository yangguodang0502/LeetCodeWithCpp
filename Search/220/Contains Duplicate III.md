#  存在重复元素 III
## 题目
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
 

Constraints:

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1

## 题解
### 算法分析
1. 使用集合记录非重复的元素
2. 遍历nums，如果nums[i]存在于集合的[nums[i]-t … nums[i]+t]之间返回true
3. 否则将nums[i]插入集合
4. 如果集合的长度大于k，将nums[i-k]的元素移除出集合
5. 遍历结束返回false
### 复杂度分析
+ 时间复杂度：O(nlogn)，n最小数组长度
+ 空间复杂度：O(k)，集合占用额外空间
### 源码
```C++ []
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> tmpSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = nums[i] >= INT32_MIN + t ? nums[i] - t : INT32_MIN;
            auto s = tmpSet.lower_bound(tmp);
            tmp = nums[i] <= INT32_MAX - t ? nums[i] + t : INT32_MAX;
            if (s != tmpSet.end() && *s <= tmp)
                return true;

            tmpSet.insert(nums[i]);

            if (tmpSet.size() > k)
                tmpSet.erase(nums[i-k]);
        }
        return false;
    }
};