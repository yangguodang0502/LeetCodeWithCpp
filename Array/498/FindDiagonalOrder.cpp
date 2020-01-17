#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> output;

        int m = matrix.size();
        if (m == 0)
            return output;

        int n = matrix[0].size();
        if (n == 0)
            return output;

        bool isEvenNum = true;
        int x = 0;

        while (x <= m + n -2)
        {
            int iM = isEvenNum ? m : n;
            int iN = isEvenNum ? n : m;
            int iMax = x < iM ? x : iM - 1;

            for (int i = iMax; i >= 0; i--)
            {
                int j = x - i;
                if (j >= iN)
                    break;
                output.push_back(isEvenNum ? matrix[i][j] : matrix[j][i]);
            }

            isEvenNum = !isEvenNum; 
            ++x;
        }        

        return output;
    }
};