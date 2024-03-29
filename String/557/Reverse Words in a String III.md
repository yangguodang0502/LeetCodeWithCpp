# 反转字符串中的单词 III
## 题目
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

## 题解
### 算法分析
1. 假设head = 0指向s头部
2. 从头遍历字符串s, i = 0 : s.length() - 1
3. if s[i] == ' ' then 
        reverse(s[head] : s[i - 1])
        head = i + 1
   end
4. reverse(s[head] : s[s.length() - 1])
5. return s
### 复杂度分析
+ 时间复杂度：O(n), n=s.length()
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void reverseString(int head, int tail, string& s) {
        while (head < tail)
        {
            s[head] ^= s[tail];
            s[tail] ^= s[head];
            s[head++] ^= s[tail--];
        }
    }

    string reverseWords(string s) {
        int head = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                reverseString(head, i - 1, s);
                head = i + 1;
            }
        }
        reverseString(head, s.length() - 1, s);
        return s;
    }
};