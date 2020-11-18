# 直线上最多的点数
## 题目

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

## 题解
### 算法分析
1. 遍历所有点，以一个点为起点，判断其他点与这个点的关系
2. 分别记录在同一水平直线、垂直直线、斜线的个数，取最大值
3. 输出最大值
### 复杂度分析
+ 时间复杂度：O(n^2)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    string computeKey(int x, int y) {
        int cd = computeCommonDivisor(x, y);
        return to_string(x / cd) + "_" + to_string(y / cd);
    }

    int computeCommonDivisor(int x, int y) {
        if (y == 0)
            return x;
        int z = x % y;
        return computeCommonDivisor(y, z);
    }

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3)
            return points.size();

        int maxCount = 1;
        unordered_map<string, int> lineMap;

        for (int i = 0; i < points.size() - 1; i++)
        {
            lineMap.clear();
            int horLines = 1;
            int verLines = 1;
            int count = 1;
            int duplicates = 0;

            for (int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if ((x1 == x2) && (y1 == y2)) {
                    duplicates++;
                }
                else if (x1 == x2) {
                    verLines++;
                    count = max(verLines, count);
                }
                else if (y1 == y2) {
                    horLines++;
                    count = max(horLines, count);
                }
                else {
                    string key = computeKey(x1 - x2, y1 - y2);
                    lineMap[key]++;
                    count = max(lineMap[key] + 1, count);
                }
            }
            
            maxCount = max(count + duplicates, maxCount);
        }
        
        return maxCount;
    }
};