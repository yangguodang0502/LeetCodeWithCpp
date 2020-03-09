# ��Ч������
## ��Ŀ
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

## ���
### �㷨����
1. ��������result��ʼ����СΪT.size()����Ԫ��Ϊ0
2. ����ջtmpStack���ڴ洢�¶ȵ������±�
3. ����j��ʾջ��Ԫ�ض�Ӧ�������±�
4. ��β����T��i = T.size() - 1 ��0
5. ����ջ��ÿ��ջ��Ϊ����T[i] >= T[tmpStack.top()]����ջ
6. ���ջΪ��result[i] = 0������result[i] = tmpStack.top() - i
7. ��i��ջ
8. ��������������result
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), n=T.size()
+ �ռ临�Ӷȣ�O(m)��m=max(result[i])
### Դ��
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