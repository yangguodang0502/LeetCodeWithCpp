#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        int n = 1 << size;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < size; j++)
            {
                if (i & (1 << j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};