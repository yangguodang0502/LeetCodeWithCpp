#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return;
        
        int i = 0;
        
        while (i < n)
        {
            if (nums[i] == 0)
            {
                int  j = i + 1;
                while (j < n)
                {
                    if (nums[j] != 0)
                    {
                        swap(nums[i], nums[j]);
                        ++i;
                    }

                    ++j;
                }
                return;
            }

            ++i;
        }
    }
};