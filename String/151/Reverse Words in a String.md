# 翻转字符串里的单词
## 题目
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

## 题解
### 算法分析
1. 假设tmp表示当前待添加的单词, res表示结果字符串
2. 从尾遍历字符串s, i = s.size() - 1 : 0
3. if s[i] != '' then tmp = s[i] + tmp
4. if s[i] == ' ' && !tmp.empty() then res += ' ' + tmp
5. if s[i] != ' ' && i == 0 then res += ' ' + tmp
6. return res
### 复杂度分析
+ 时间复杂度：O(n), n=s.size()
+ 空间复杂度：O(m), m = max(tmp.size())
### 源码
```C++ []
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        
        string res = "";
        string tmp = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            bool addTmp = false;

            if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    addTmp = true;
                }
            }
            else
            {
                tmp = s[i] + tmp;

                if (i == 0)
                {
                    addTmp = true;
                }
            }

            if (addTmp)
            {
                if (!res.empty())
                    res += ' ';
                res += tmp;
                tmp = "";
            }
        }

        return res;
    }
};