#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if (matrix.empty())
            return output;

        int r0 = 0;
        int c0 = 0;
        int rm = matrix.size() - 1;
        int cm = matrix[0].size() - 1;
        int r;
        int c;

        while (r0 <= rm && c0 <= cm)
        {
            r = r0;
            c = c0;
            while (c <= cm)
            {
                output.push_back(matrix[r][c]);
                ++c;
            }
            
            r = r0 + 1;
            c = cm;
            while (r <= rm)
            {
                output.push_back(matrix[r][c]);
                ++r;
            }

            if (r0 < rm && c0 < cm)
            {
                r = rm;
                c = cm - 1;
                while (c > c0)
                {
                    output.push_back(matrix[r][c]);
                    --c;
                }

                r = rm;
                c = c0;
                while (r > r0)
                {
                    output.push_back(matrix[r][c]);
                    --r;
                }
            }            

            ++r0;
            ++c0;
            --rm;
            --cm;
        }        

        return output;
    }
};