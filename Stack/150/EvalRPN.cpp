#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> tmpStack;
        
        for (int i = 0; i < n; i++)
        {
            string str = tokens[i];
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = tmpStack.top();
                tmpStack.pop();

                int left = tmpStack.top();
                tmpStack.pop();

                int result = evalNumbers(left, right, str);
                tmpStack.push(result);
            }
            else
            {
                int val = stoi(str);
                tmpStack.push(val);
            }            
        }
        
        return tmpStack.top();
    }

    int evalNumbers(int left, int right, string operation)
    {
        if (operation == "+")
        {
            return left + right;
        }
        else if (operation == "-")
        {
            return left - right;
        }
        else if (operation == "*")
        {
            return left * right;
        }
        else if (operation == "/")
        {
            return left / right;
        }
        return 0;
    }
};