#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp (i+1, 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    temp[j] = 1;
                else
                    temp[j] = output[i-1][j-1] + output[i-1][j];
            }
            output.push_back(temp);
        }

        return output;
    }
};