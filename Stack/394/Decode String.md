# �ַ�������
## ��Ŀ
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

## ���
### �㷨����
1. ʹ��ջstrStack�洢�ַ�����numStack�洢����
2. �����ַ���result���ڴ洢���������num=0�洢�м�����
3. �����ַ���s��i = 0 : s.size() - 1
4. ����ַ�s[i] == '[', ����ջresult��strStack����ջnum��numStack
5. ����ַ�s[i] == ']'�����ջnumStackջ��Ԫ��count����ջstrStackջ��Ԫ��str��
   ����count��str += result, result = str
6. ����ַ�s[i]Ϊ���֣�����num = num * 10 + s[i]
7. ����result += s[i]
8.  ����result
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)
+ �ռ临�Ӷȣ�O(n)
### Դ��
```C++ []
class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string result;
        int num = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                strStack.push(result);
                result = "";

                numStack.push(num);
                num = 0;
            }
            else if (s[i] == ']')
            {
                int count = numStack.top();
                numStack.pop();

                string str = strStack.top();
                strStack.pop();

                for (int j = 0; j < count; j++)
                {
                    str += result;
                }

                result = str;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            else
            {
                result.push_back(s[i]);
            }            
        }        
        
        return result;
    }
};