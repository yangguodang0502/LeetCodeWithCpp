#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = rowIndex;
        vector<int> res (i + 1, 1);
        long val = res[0];

        for (int j = 1; j < i; ++j)
        {
            val = val * (i - j + 1) / j;
            res[j] = (int)val;
        }
        
        return res;
    }
};