#include <string>
#include <map>
#include <stack>

using namespace std;

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