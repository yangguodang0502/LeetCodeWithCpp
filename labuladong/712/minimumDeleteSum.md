# Minimum ASCII Delete Sum for Two Strings
## 题目

Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].

## 题解
### 解题思路
1. 使用动态规划,m=s1.size(),n=s2.size()
2. 状态转移方程：dp[i][j] = s1[i] == s2[j] 
    ? dp[i+1][j+1]
    : min(dp[i+1][j]+s1[i], dp[i][j+1]+s2[j])
3. 初始dp[m][n]=0,dp[i][n]=dp[i+1][n]+s1[i],dp[m][j]=dp[m][j+1]+s2[j]
4. 返回dp[0][0]

### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
### 代码

```cpp
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