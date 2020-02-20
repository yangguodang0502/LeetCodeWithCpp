#include <vector>

using namespace std;

#define INT_MAX _INT_MAX_

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int len = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                len = min(len, i - left + 1);
                sum -= nums[left++];
            }
        }

        return len != INT_MAX ? len : 0;
    }
};