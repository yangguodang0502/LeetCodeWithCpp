# 最长公共前缀
## 题目
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

## 题解
### 算法分析
1. 公式：prefix = strs[0], prefix = commonPrefix(prefix, strs[i]), i = 1 : strs.length() - 1
2. 遍历strs获取当前的公共前缀prefix，直到prefix为空或者遍历结束
### 复杂度分析
+ 时间复杂度：O(m*n)，m为strs长度，n为strs[i]长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0)
            return "";

        string prefix = strs[0];
        for (int i = 1; i < size; i++)
        {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix == "")
                return "";
        }

        return prefix;
    }

    string commonPrefix(string left, string right) {
        int minSize = min(left.size(), right.size());
        
        for (int i = 0; i < minSize; i++)
        {
            if (left[i] != right[i])
                return left.substr(0, i);
        }
        
        return left.substr(0, minSize);
    }
};