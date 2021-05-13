# Minimum Path Sum
## 题目
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:
![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

## 题解
### 解题思路
1. 使用动态规划,m=grid.size(),n=grid[0].size()
2. 动态转移方程dp(grid,m-1,n-1) = min(dp(grid,i-1,j), dp(grid,i，j-1)) + grid[i][j]
3. base case:if i==0 && j==0 return grid(0,0)
    if i < 0 or j < 0 return INT_MAX
4. 定义备忘录memo[m][n]，初始化-1
5. if memo[i][j] != -1 return memo[i][j]
6. 返回memo[i][j]

### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(memo, grid, m-1, n-1);
    }

    int dp(vector<vector<int>>& memo, vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[0][0];
        }
        if (i < 0 || j < 0) {
            return __INT_MAX__;
        }
        if (memo[i][j] == -1) {
            memo[i][j] = min(dp(memo, grid, i-1, j), dp(memo, grid, i, j-1)) + grid[i][j];
        }
        return memo[i][j];
    }
};