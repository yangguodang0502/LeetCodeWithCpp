# 只出现一次的数字
## 题目
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1


Example 2:
Input: [4,1,2,1,2]
Output: 4

## 题解
### 算法分析
1. 定义哈希表用于存储不重复的元素
2. 遍历nums，如果元素不存在于哈希表则加入哈希表，否则从哈希表中删除
3. 遍历结束返回哈希表的首元素
### 复杂度分析
+ 时间复杂度：O(n)，n为nums大小
+ 空间复杂度：O(n), 哈希表占用的空间
### 源码
```C++ []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = numSet.find(nums[i]);
            if (iter == numSet.end())
                numSet.insert(nums[i]);
            else
                numSet.erase(iter);
        }
        return *numSet.begin();
    }
};