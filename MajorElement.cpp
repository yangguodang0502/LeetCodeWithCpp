#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                num = nums[i];
            }
            count += (nums[i] == num ? 1 : -1);
        }
        return num;
    }
};