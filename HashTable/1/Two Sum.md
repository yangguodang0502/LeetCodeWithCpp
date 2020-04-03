# 两数之和
## 题目
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

## 题解
### 算法分析
1. 定义数组result用于存储结果，定义哈希表hasMap用于存储待匹配的元素值和匹配的下标
2. 遍历nums,num=nums[i]，判断num是否存在于哈希表，如果存在将对应的下标和当前下标加入result并返回
3. 否则将key=target-num和当前下标插入到哈希表中
4. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hasMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (hasMap.count(num) > 0)
            {
                result.push_back(hasMap[num]);
                result.push_back(i);
                return result;
            }
            else
            {
                int key = target - num;
                if (hasMap.count(key) <= 0)
                {
                    hasMap.insert(make_pair(key, i));
                }
            }
        }
        
        return result;
    }
};