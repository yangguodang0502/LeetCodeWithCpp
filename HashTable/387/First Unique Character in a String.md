# 字符串中的第一个唯一字符
## 题目
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

## 题解
### 算法分析
1. 使用哈希表，遍历字符串将字符和出现次数记录到哈希表
2. 再次遍历字符串判断是否有字符出现次数为1，如果有返回i
3. 遍历结束返回-1
### 复杂度分析
+ 时间复杂度：O(n)，n字符串长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (hashMap.count(ch))
            {
                hashMap[ch] += 1;
            }
            else
            {
                hashMap.insert(make_pair(ch, 1));
            }            
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (hashMap[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};