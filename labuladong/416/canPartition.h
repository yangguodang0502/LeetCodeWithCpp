#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum / 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j-nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }

        return dp[sum];
    }
};