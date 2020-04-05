# 两个数组的交集 II
## 题目
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

## 题解
### 算法分析
1. 使用哈希表，遍历数组nums1记录整数和计数
2. 遍历数组num2,num=nums2[i]
3. 如果num存在于哈希表并且计数大于0，将计数递减并将num加入结果数组
4. 遍历结束，返回结果数组
### 复杂度分析
+ 时间复杂度：O(n)，n最小数组长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> hashMap;
        vector<int> result;

        for (auto &&num : nums1)
        {
            if (hashMap.count(num))
            {
                ++hashMap[num];
            }
            else
            {
                hashMap[num] = 1;
            }            
        }
        
        for (auto &&num : nums2)
        {
            auto iter = hashMap.find(num);
            if (iter != hashMap.end() && iter->second > 0)
            {
                --iter->second;
                result.push_back(num);
            }
        }
        
        return result;
    }
};