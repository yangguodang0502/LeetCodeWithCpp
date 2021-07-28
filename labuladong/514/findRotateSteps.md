# Freedom Trail
## 题目
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.
 

Example 1:

![](https://assets.leetcode.com/uploads/2018/10/22/ring.jpg)

Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
Also, we need 1 more step for spelling.
So the final output is 4.
Example 2:

Input: ring = "godding", key = "godding"
Output: 13
 

Constraints:

1 <= ring.length, key.length <= 100
ring and key consist of only lower case English letters.
It is guaranteed that key could always be spelled by rotating ring.

## 题解
### 解题思路
1. 使用动态规划,m=ring.size(),n=key.size()
2. 动态转移方程:res = min(res, 1 + dp(ring, k , key, j + 1))
3. base case:if j==key.size() then return 0
4. 定义备忘录memo[m][n]，初始化0
5. memo[i][j] = res
6. 返回dp(ring, 0, key, 0)

### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
### 代码

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();

        memo.resize(m, vector<int>(n, 0));

        for (int i = 0; i < ring.size(); i++) {
            charToIndex[ring[i]].push_back(i);
        }

        return dp(ring, 0, key, 0);
    }

    int dp(string& ring, int i, string& key, int j) {
        if (j == key.size()) {
            return 0;
        }

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int n = ring.size();
        int res = INT_MAX;
        for (int k : charToIndex[key[j]]) {
            int delta = abs(k-i);
            delta = min(delta, n - delta);
            int subProblem = dp(ring, k, key, j + 1);
            res = min(res, 1 + delta + subProblem);
        }
        memo[i][j] = res;
        return res;
    }

private:
    unordered_map<char, vector<int>> charToIndex;
    vector<vector<int>> memo;    
};