#include <vector>

using namespace std;

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