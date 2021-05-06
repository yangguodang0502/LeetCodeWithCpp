# Edit Distance
## 题目
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

## 题解
### 解题思路
1. 使用动态规划，定义dp[m+1][n+1]
2. dp[i][0] = i, i = 1:m
3. dp[0]j] = j, j = 1:n
4. 如果word1[i] == word1[j],则dp[i][j] = dp[i-1][j-1]
5. 否则dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)
6. 返回dp[m][n]
### 复杂度分析
+ 时间复杂度：O(n*m)
+ 空间复杂度：O(n*m)
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m * n == 0) {
            return m + n;
        }

        int dp[m+1][n+1];

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int left = dp[i-1][j]+1;
                int down = dp[i][j-1]+1;
                int left_down = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    left_down += 1;
                }
                dp[i][j] = min(left, min(down, left_down));
            }
        }

        return dp[m][n];
    }
};