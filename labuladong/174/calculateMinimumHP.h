#include <vector>

using namespace std;

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