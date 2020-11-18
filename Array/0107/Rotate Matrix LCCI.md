# 搜索插入位置
## 题目
Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

 

Example 1:

Given matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

Rotate the matrix in place. It becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

Rotate the matrix in place. It becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

## 题解
### 算法分析
1. 旋转符合公式：matrix[row][col] = matrix[col][n−row−1]​	
2. 先进行水平轴翻转： matrix[row][col] = matrix[n−row−1][col]
3. 再进行主对角线翻转： matrix[row][col] = matrix[col][row]​
### 复杂度分析
+ 时间复杂度：O(n^2)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++)
        {
            for (int col = 0; col < n; col++)
            {
                swap(matrix[row][col], matrix[n-row-1][col]);
            }
        }
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < row; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};