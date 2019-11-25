#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int add = 0;
        res.push_back(add);
        for (int i = 0; i < n; i++)
        {
            add = 1 << i;
            for (int j = res.size() - 1; j >= 0; j--)
            {
                res.push_back(res[j] + add);
            }
        }
        return res;
    }
};