#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange {-1, -1};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                targetRange[0] = i;
                break;
            }
        }

        if (targetRange[0] == -1)
            return targetRange;

        for (int i = nums.size() - 1; i >= targetRange[0]; --i)
        {
            if (nums[i] == target)
            {
                targetRange[1] = i;
                break;
            }
        }

        return targetRange;
    }
};