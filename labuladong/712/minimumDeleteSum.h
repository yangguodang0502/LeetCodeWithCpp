#include <string>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        int dp[m+1][n+1];
        dp[m][n] = 0;
        for (int i = m-1; i >= 0; i--) {
            dp[i][n]=dp[i+1][n] + s1[i];
        }
        for (int j = n-1; j >= 0; j--) {
            dp[m][j]=dp[m][j+1] + s2[j];
        }

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                dp[i][j] = s1[i] == s2[j] 
                    ? dp[i+1][j+1] 
                    : min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
            }
        }

        return dp[0][0];
    }
};