# 实现 strStr()
## 题目
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

## 题解
### 算法分析
1. 公式：len = haystack.length() - i, len >= needle.length() && index < needle.length() && haystack[i+index] == needle[index], index++
2. 遍历haystack根据上述公式进行判断，如果存在index == needle.length()，则结果为i,否则为-1
### 复杂度分析
+ 时间复杂度：O(m*n)，m为haystack长度，n为needle长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenB = needle.length();
        if (lenB == 0)
            return 0;

        int lenA = haystack.length();
        for (int i = 0; i < lenA; ++i)
        {
            int len = lenA - i;
            if (len < lenB)
                return -1;

            int index = 0;
            while (index < lenB && haystack[i+index] == needle[index])
            {
                ++index;
            }
            
            if (index == lenB)
                return i;
        }

        return -1;
    }
};