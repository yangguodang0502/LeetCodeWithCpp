# 存在重复元素
## 题目
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true


## 题解
### 算法分析
1. 使用哈希表存储已经访问过的元素
2. 遍历nums，如果哈希表中存在就返回true，否则将元素插入哈希表
3. 遍历结束返回false
### 复杂度分析
+ 时间复杂度：O(n)，n为nums大小
+ 空间复杂度：O(n)，哈希表占用空间
### 源码
```C++ []
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet;
        for (auto num:nums)
        {
            if (numSet.find(num) != numSet.end())
                return true;
            numSet.insert(num);
        }
        return false;
    }
};