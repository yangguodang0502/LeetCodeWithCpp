#include <vector>

using namespace std;

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