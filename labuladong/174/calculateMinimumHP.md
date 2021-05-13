# Dungeon Game
## 题目
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

Example 1:
![](https://assets.leetcode.com/uploads/2021/03/13/dungeon-grid-1.jpg)

Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
Example 2:

Input: dungeon = [[0]]
Output: 1
 

Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000

## 题解
### 解题思路
1. 使用动态规划,m=grid.size(),n=grid[0].size()
2. 动态转移方程res = min(dp(grid,i+1,j), dp(grid,i，j+1)) - grid[i][j]
3. base case:if i==m-1 && j==n-1 return grid(i,j) >=0 ? 1 : -grid(i,j)+1
    if i == m or j == m return INT_MAX
4. 定义备忘录memo[m][n]，初始化-1
5. if memo[i][j] == -1 then memo[i][j] = res <= 0 ? 1 : res
6. 返回memo[i][j]

### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
### 代码

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(memo, dungeon, 0, 0);
    }

    int dp(vector<vector<int>>& memo, vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m-1 && j == n-1) {
            return grid[i][j] >= 0 ? 1 : -grid[i][j]+1;
        }
        if (i == m || j == n) {
            return __INT_MAX__;
        }
        if (memo[i][j] == -1) {
            int res = min(dp(memo, grid, i+1, j), dp(memo, grid, i, j+1)) - grid[i][j];
            memo[i][j] = res <= 0 ? 1 : res;
        }
        return memo[i][j];
    }
};