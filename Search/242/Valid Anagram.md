# 有效的字母异位词
## 题目
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

## 题解
### 算法分析
1. 使用哈希表记录较长字符串的字符出现次数
2. 遍历较短字符串，判断字符是否在哈希表中存在
3. 如果不存在或者值为0，则返回false
4. 否则对应的值-1
5. 循环结束返回true
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() > t.length())
        {
            return isAnagram(t, s);
        }
        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.length(); i++)
        {
            if (hashMap.count(s[i]))
            {
                hashMap[s[i]]++;
            }
            else
            {
                hashMap[s[i]] = 1;
            }            
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (!hashMap.count(t[i]) || hashMap[t[i]] == 0)
            {
                return false;
            }
            else
            {
                hashMap[t[i]]--;
            }            
        }
        return true;
    }
};