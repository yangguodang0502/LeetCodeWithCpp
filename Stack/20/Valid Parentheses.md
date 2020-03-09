# ��Ч������
## ��Ŀ
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

## ���
### �㷨����
1. ʹ�ù�ϣ���¼�����Ŷ�Ӧ�������ţ�����ջopenBrackets�洢������
2. ��ͷ�����ַ���s��i = 0 : s.size() - 1
3. ���s[i]Ϊ�����ţ�������ջ
4. ���s[i]Ϊ�����ţ����ջΪ���򷵻�false
5. ����ȡ��ջ���ַ���������ַ���Ӧ����������s[i]����ȣ��򷵻�false
6. ��������������ջ�Ƿ�Ϊ��
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)��n=s.size()
+ �ռ临�Ӷȣ�O(n)
### Դ��
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