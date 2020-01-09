#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> intStack;
        intStack.push(-1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s.at(i) == '(')
            {
                intStack.push(i);
            }
            else
            {
                intStack.pop();
                if (intStack.empty())
                {
                    intStack.push(i);
                }
                else
                {
                    ret = max(ret, i - intStack.top());
                }
            }            
        }
        return ret;
    }
};