#  无重复字符的最长子串
## 题目
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

## 题解
### 算法分析
1. 定义哈希表存储字符对应的下标，定义length存储最大长度
2. 遍历字符串，使用滑动窗口[j,i)，判断字符是否存在于哈希表
3. 如果存在更新j取字符对应的下标和j的最大值
4. 计算length取length和i-j+1
5. 更新哈希表记录字符对应的下标为i+1
6. 返回length
### 复杂度分析
+ 时间复杂度：O(n)，n为字符串长度
+ 空间复杂度：O(n)，哈希表占用空间
### 源码
```C++ []
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;
        int length = 0;
        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (hashMap.count(ch))
            {
                j = max(hashMap[ch], j);
            }

            length = max(length, i - j + 1);
            hashMap[ch] = i + 1;
        }
        
        return length;
    }
};