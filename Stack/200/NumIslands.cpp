#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;
        int m = grid.size();
        
        for (int i = 0; i < m; i++)
        {
            int n = grid[i].size();
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++nums;
                    stack<pair<int, int>> arounds;
                    arounds.push(pair<int, int>(i, j));
                    grid[i][j] = '0';

                    while (!arounds.empty())
                    {
                        pair<int, int> pos = arounds.top();
                        arounds.pop();

                        int r = pos.first;
                        int c = pos.second;

                        if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        {
                            arounds.push(pair<int, int>(r - 1, c));
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < m && grid[r + 1][c] == '1')
                        {
                            arounds.push(pair<int, int>(r + 1, c));
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        {
                            arounds.push(pair<int, int>(r, c - 1));
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < n && grid[r][c + 1] == '1')
                        {
                            arounds.push(pair<int, int>(r, c + 1));
                            grid[r][c + 1] = '0';
                        }
                    }                    
                }
            }            
        }
        
        return nums;
    }
};