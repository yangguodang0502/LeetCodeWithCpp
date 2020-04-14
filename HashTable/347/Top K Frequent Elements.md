#  前 K 个高频元素
## 题目
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## 题解
### 算法分析
1. 使用哈希表统计数字对应的次数，使用优先队列存储前K大的元素
2. 遍历数组填充哈希表
3. 遍历哈希表，判断队列是否已达到k，如果为达到填充优先队列
4. 否则如果当前元素的个数大于队列头部元素则出队并将改元素填充到队列
5. 遍历优先队列将元素加入到结果数组
6. 返回结果数组
### 复杂度分析
+ 时间复杂度：O(nlog(n))，n为数组长度
+ 空间复杂度：O(n)，哈希表和优先队列占用空间
### 源码
```C++ []
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto &&num : nums)
        {
            hashMap[num]++;
        }        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        for (auto &&it : hashMap)
        {
            if (priorityQueue.size() == k)
            {
                if (it.second > priorityQueue.top().first)
                {
                    priorityQueue.pop();
                    priorityQueue.push(make_pair(it.second, it.first));
                }                
            }
            else
            {
                priorityQueue.push(make_pair(it.second, it.first));
            }            
        }
        
        vector<int> result;
        while (!priorityQueue.empty())
        {
            result.push_back(priorityQueue.top().second);
            priorityQueue.pop();
        }
        
        return result;
    }
};