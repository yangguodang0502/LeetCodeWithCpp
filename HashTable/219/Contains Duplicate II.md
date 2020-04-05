#  存在重复元素 II
## 题目
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

## 题解
### 算法分析
1. 使用哈希表记录非重复的元素
2. 遍历nums，如果nums[i]存在于哈希表中返回true
3. 否则将nums[i]插入哈希表
4. 如果哈希表的长度大于k，将nums[i-k]的元素移除出哈希表
5. 遍历结束返回false
### 复杂度分析
+ 时间复杂度：O(n)，n最小数组长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hashSet.count(nums[i]))
                return true;

            hashSet.insert(nums[i]);

            if (hashSet.size() > k)
                hashSet.erase(nums[i-k]);
        }
        return false;
    }
};