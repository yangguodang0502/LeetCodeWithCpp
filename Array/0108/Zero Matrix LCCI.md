# 零矩阵
## 题目
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

 

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

## 题解
### 算法分析
1. 定义两个bool数组用于存储行和列是否存在0
2. 遍历矩阵记录存在0的行列
3. 遍历矩阵判断行列是否存在0，如果是则赋值0
### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m+n)
### 源码
```C++ []
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> mV(m, false);
        vector<bool> nV(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mV[i] = true;
                    nV[j] = true;
                }
            }            
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mV[i] || nV[j])
                {
                    matrix[i][j] = 0;
                }
            }            
        }
    }
};