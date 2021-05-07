# Longest Palindromic Subsequence
## 题目
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

## 题解
### 解题思路
1. 使用动态规划,n=s.size()
2. 状态转移方程：dp[i][j] = s[i] == s[j] 
    ? 2+dp[i+1][j-1]
    : max(dp[i+1][j], dp[i][j-1])
3. 初始dp[i][i]=1,其他为0
4. 返回dp[0][n-1]

### 复杂度分析
+ 时间复杂度：O(n^2)
+ 空间复杂度：O(n^2)
### 代码

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j]
                    ? 2+dp[i+1][j-1]
                    : max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};