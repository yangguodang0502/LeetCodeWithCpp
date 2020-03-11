# 逆波兰表达式求值
## 题目
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

## 题解
### 算法分析
1. 定义n = tokens.size()，定义tmpStack用于存储字符串
2. 从头遍历tokens，i = 0 : n-1
3. 如果tokens[i]是数字，入栈
4. 否则出栈前两个数字并计算，将计算结果入栈
5. 遍历结束，返回栈顶元素
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O((n + 1)/2)
### 源码
```C++ []
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