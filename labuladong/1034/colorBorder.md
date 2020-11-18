#  边框着色
## 题目
Given a 2-dimensional grid of integers, each value in the grid represents the color of the grid square at that location.

Two squares belong to the same connected component if and only if they have the same color and are next to each other in any of the 4 directions.

The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).

Given a square at location (r0, c0) in the grid and a color, color the border of the connected component of that square with the given color, and return the final grid.

 

Example 1:

Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
Output: [[3, 3], [3, 2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
Output: [[1, 3, 3], [2, 3, 3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 

Note:

1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000

## 题解
### 算法分析
1. 使用dfs遍历与该坐标相连通的坐标，并将其染色
2. 使用一个与grid大小一样的矩阵记录已访问的节点
3. 判断坐标是否为连通坐标的边界
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int oldColor = grid[r0][c0];
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        fill(grid, visited, r0, c0, oldColor, color);
        return grid;
    }

    void fill(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int oldColor, int newColor) {
        if (!inArea(grid, r, c))
            return;
        if (visited[r][c])
            return;
        if (grid[r][c] != oldColor)
            return;

        visited[r][c] = true;

        if (r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() -1
        || (r >= 1 && grid[r-1][c] != oldColor && !visited[r-1][c])
        || (c >= 1 && grid[r][c-1] != oldColor && !visited[r][c-1])
        || (r < grid.size() - 1 && grid[r+1][c] != oldColor && !visited[r+1][c])
        || (c < grid[0].size() - 1 && grid[r][c+1] != oldColor && !visited[r][c+1]))
            grid[r][c] = newColor;

        fill(grid, visited, r - 1, c, oldColor, newColor);
        fill(grid, visited, r + 1, c, oldColor, newColor);
        fill(grid, visited, r, c - 1, oldColor, newColor);
        fill(grid, visited, r, c + 1, oldColor, newColor);
    }

    bool inArea(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >=0 && c < grid[0].size();
    }
};