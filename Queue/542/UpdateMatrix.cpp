#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        if (rowCount == 0)
            return matrix;

        int colCount = matrix[0].size();        
        vector<vector<int>> result(rowCount, vector<int>(colCount, 0));
        queue<pair<int,int>> que;

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < colCount; j++)
            {
                if (matrix[i][j] == 0)
                {
                    que.push(make_pair(i, j));
                }
                else
                {
                    result[i][j] = INT_MAX;
                }
            }            
        }

        int diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!que.empty())
        {
            pair<int,int> pos = que.front();
            int i = pos.first;
            int j = pos.second;
            que.pop();

            for (int index = 0; index < 4; index++)
            {
                int diff_i = diff[index][0];
                int diff_j = diff[index][1];
                int new_i = i + diff_i;
                int new_j = j + diff_j;

                if (new_i >= 0 && new_i < rowCount && new_j >= 0 && new_j < colCount
                    && result[new_i][new_j] > result[i][j] + 1)
                {
                    result[new_i][new_j] = result[i][j] + 1;
                    que.push(make_pair(new_i, new_j));
                }
            }
        }   

        return result;     
    }
};