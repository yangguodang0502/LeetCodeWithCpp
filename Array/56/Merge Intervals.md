# 合并区间
## 题目
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]

## 题解
### 算法分析
1. 将intervals根据左端点进行排序
2. 定义merges数组用于存储融合后的
3. 遍历intervals
4. 如果merges数组为空或者其末尾元素的右端数值小于intervals[i]的左端元素，则将intervals加入merges末尾
5. 否则将末尾元素的右端数值替换为intervals[i]的右端元素
### 复杂度分析
+ 时间复杂度：O(nlogn)
+ 空间复杂度：O(logn)
### 源码
```C++ []
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merges;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (merges.empty() || merges.back()[1] < intervals[i][0]) {
                merges.push_back(intervals[i]);
            }
            else {
                merges.back()[1] = max(merges.back()[1], intervals[i][1]);
            }
        }

       return merges; 
    }
};