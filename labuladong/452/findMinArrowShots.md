# Minimum Number of Arrows to Burst Balloons
## 题目
There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
 

Constraints:

1 <= points.length <= 104
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

## 题解
### 解题思路
1. 使用动态规划
2. 将intervals按intervals[i][1]升序排序
3. 定义弓箭数量count=1，end=intervals[0][1]
4. 遍历排序后的intervals,如果intervals[i][0]>end,则count++，end=intervals[i][1]
5. 返回count

### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 代码

```cpp
bool compare(vector<int>& a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                count++;
                end = intervals[i][1];
            }
        }
        return count;
    }
};