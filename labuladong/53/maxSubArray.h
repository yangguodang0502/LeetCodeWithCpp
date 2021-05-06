#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int dp0 = nums[0];
        int dp1;
        int res = dp0;
        for (int i = 1; i < n; i++) {
            dp1 = max(nums[i], nums[i] + dp0);
            dp0 = dp1;
            res = max(res, dp1);
        }
        return res;
    }
};