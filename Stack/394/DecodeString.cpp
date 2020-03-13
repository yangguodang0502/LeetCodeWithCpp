#include <string>
#include <stack>

using namespace std;

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