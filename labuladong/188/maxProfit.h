#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n / 2) {
            return maxProfit_infinity(prices);
        }

        int dp[n][k+1][2];
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
        for (int j = 1; j < k+1; j++) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }

    int maxProfit_infinity(vector<int>& prices) {
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, dpi0 - prices[i]);
        }
        return dpi0;
    }
};