# 两个数组的交集
## 题目
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]



Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]


Note:


	Each element in the result must be unique.
	The result can be in any order.

## 题解
### 算法分析
1. 定义哈希表存储nums1的元素
2. 遍历nums1，将元素添加到哈希表
3. 定义数组result存储结果
4. 遍历nums2，判断元素是否存在于哈希表，如果存在则加入result并从哈希表中移除
5. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n)，n=max(nums1.size(), nums2.size())
+ 空间复杂度：O(m), 哈希表占用的空间,m=min(nums1.size(), nums2.size())
### 源码
```C++ []
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        unordered_set<int> numSet;
        for (auto &&i : nums1)
        {
            if (numSet.find(i) == numSet.end())
                numSet.insert(i);
        }
        
        vector<int> result;
        for (auto &&i : nums2)
        {
            if (numSet.find(i) != numSet.end())
            {
                numSet.erase(i);
                result.push_back(i);
            }
        }
        
        return result;
    }
};