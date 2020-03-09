# 有效的括号
## 题目
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

## 题解
### 算法分析
1. 使用哈希表记录左括号对应的右括号，定义栈openBrackets存储左括号
2. 从头遍历字符串s，i = 0 : s.size() - 1
3. 如果s[i]为左括号，将其入栈
4. 如果s[i]为右括号，如果栈为空则返回false
5. 否则取出栈顶字符，如果该字符对应的右括号与s[i]不相等，则返回false
6. 遍历结束，返回栈是否为空
### 复杂度分析
+ 时间复杂度：O(n)，n=s.size()
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    bool isValid(string s) {
        map<char, char> bracketMap;
        bracketMap['('] = ')';
        bracketMap['{'] = '}';
        bracketMap['['] = ']';
        
        stack<char> openBrackets;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                openBrackets.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (openBrackets.empty())
                    return false;
                char tmp = openBrackets.top();
                if (ch != bracketMap[tmp])
                    return false;
                openBrackets.pop();
            }
        }
        return openBrackets.empty();
    }
};