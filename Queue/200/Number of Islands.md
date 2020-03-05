# ��ת����
## ��Ŀ
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

## ���
### �㷨����
1. �����Ҵ��ϵ��±���grid���趨nums=0
2. ��grid[i][j]==1ʱ��++nums����pair<i, j>��ӣ�grid[i][j]��Ϊ0
3. �������У�����pair<i, j>���ж�<i,j>�������Ƿ����1�������������ӣ�����Ϊ0
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(m*n)
+ �ռ临�Ӷȣ�O(min(m,n))
### Դ��
```C++ []
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
                    queue<pair<int, int>> arounds;
                    arounds.push(pair<int, int>(i, j));
                    grid[i][j] = '0';

                    while (!arounds.empty())
                    {
                        pair<int, int> pos = arounds.front();
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