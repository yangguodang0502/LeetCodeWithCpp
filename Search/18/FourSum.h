#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 4)
            return ret;

        sort(nums.begin(), nums.end());

        int i, j, l, r;
        for (i = 0; i <= len - 4; i++)
        {          
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (j = i + 1; j <= len - 3; j++)
            {           
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                l = j + 1;
                r = len - 1;
                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                    {
                        r--;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                    {
                        l++;
                    }
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1])
                        {
                            r--;
                        }                        
                        l++;
                        r--;
                    }                    
                }                
            }
        }

        return ret;
    }
};