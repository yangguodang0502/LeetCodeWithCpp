# 有效的括号
## 题目
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

## 题解
### 算法分析
1. 定义数组result初始化大小为T.size()所有元素为0
2. 定义栈tmpStack用于存储温度的数组下标
3. 定义j表示栈顶元素对应的数组下标
4. 从尾遍历T，i = T.size() - 1 ：0
5. 遍历栈，每当栈不为空且T[i] >= T[tmpStack.top()]，出栈
6. 如果栈为空result[i] = 0，否则result[i] = tmpStack.top() - i
7. 将i入栈
8. 遍历结束，返回result
### 复杂度分析
+ 时间复杂度：O(n), n=T.size()
+ 空间复杂度：O(m)，m=max(result[i])
### 源码
```C++ []
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> tmpStack;

        for (int i = T.size() - 1; i >= 0; i--)
        {
            while (!tmpStack.empty() && T[i] >= T[tmpStack.top()])
            {
                tmpStack.pop();
            }
            
            result[i] = tmpStack.empty() ? 0 : tmpStack.top() - i;
            tmpStack.push(i);
        }

        return result; 
    }
};