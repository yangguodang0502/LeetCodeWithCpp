#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int sumAll = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumAll += nums[i];
        }
        
        int sumLeft = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumLeft == sumAll - sumLeft - nums[i])
            {
                return i;
            }
            sumLeft += nums[i];
        }

        return -1;
    }
};