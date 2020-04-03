# 同构字符串
## 题目
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true


Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
 You may assume both s and t have the same length.

## 题解
### 算法分析
1. 定义哈希表sHasMap和tHasMap分别存储字母对应的下标
2. 遍历字符串s和t，判断哈希表是否存在字符s[i]和字符t[i]
3. 如果都存在则如果两个下标不相等返回false
4. 否则如果其中一个存在则返回false
5. 否则将当前下标i插入到哈希表中
6. 遍历结束返回true
### 复杂度分析
+ 时间复杂度：O(n)，n字符串长度
+ 空间复杂度：O(2n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> sHasMap;
        unordered_map<char, int> tHasMap;

        for (int i = 0; i < s.size(); i++)
        {
            if (sHasMap.count(s[i]) > 0 && tHasMap.count(t[i]) > 0)
            {
                if (sHasMap[s[i]] != tHasMap[t[i]])
                    return false;
            }
            else if (sHasMap.count(s[i]) > 0 || tHasMap.count(t[i]) > 0)
            {
                return false;
            }
            else
            {
                sHasMap[s[i]] = i;
                tHasMap[t[i]] = i;
            }
        }
        
        return true;
    }
};