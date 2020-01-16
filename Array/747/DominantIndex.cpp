#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int maxIndex = 0;
        int sumAll = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != maxIndex && nums[maxIndex] < 2 * nums[i])
            {
                return -1;
            }
        }

        return maxIndex;
    }
};