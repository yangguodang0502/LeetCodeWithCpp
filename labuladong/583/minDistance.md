# Delete Operation for Two Strings
## 题目
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

## 题解
### 解题思路
1. 使用动态规划,m=word1.size(),n=word2.size()
2. 先计算两字符串的最大公共子串长度lcs
3. 返回res=m+n-2*lcs

### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int lcs = longestCommonSubsequence(word1, word2);
        return m+n-2*lcs;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if (m==0 || n==0) {
            return 0;
        }

        int dp[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = text1[i-1] == text2[j-1] 
                        ? 1 + dp[i-1][j-1] 
                        : max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};