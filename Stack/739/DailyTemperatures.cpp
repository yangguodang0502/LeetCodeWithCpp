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