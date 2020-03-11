#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;

        for (const auto &num : nums)
            sum += num;
        
        if (S > sum)
            return 0;
        
        S += sum;
        if (S % 2 != 0)
            return 0;

        int sumP = S / 2;
        vector<int> dp(sumP+1, 0);
        dp[0] = 1;

        for (const auto &num : nums)
        {
            for (int i = sumP; i >= num; i--)
            {
                dp[i] += dp[i - num];
            }            
        }
        
        return dp[sumP];
    }
};