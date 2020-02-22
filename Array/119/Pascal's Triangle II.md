# 杨辉三角 II
## 题目
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

![PascalTriangleAnimated2.gif](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

## 题解
### 算法分析
1. 假设i = rowIndex, j表示列序号, res表示结果数组
2. res[0] = 1
3. res[j] = res[j - 1] * (i - j + 1) / j, j = 1 : i
### 复杂度分析
+ 时间复杂度：O(i)，i = rowIndex
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = rowIndex;
        vector<int> res (i + 1, 1);
        long val = res[0];

        for (int j = 1; j < i; ++j)
        {
            val = val * (i - j + 1) / j;
            res[j] = (int)val;
        }
        
        return res;
    }
};