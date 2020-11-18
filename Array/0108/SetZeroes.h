#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> mV(m, false);
        vector<bool> nV(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mV[i] = true;
                    nV[j] = true;
                }
            }            
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mV[i] || nV[j])
                {
                    matrix[i][j] = 0;
                }
            }            
        }
    }
};