#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++)
        {
            for (int col = 0; col < n; col++)
            {
                swap(matrix[row][col], matrix[n-row-1][col]);
            }
        }
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < row; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};