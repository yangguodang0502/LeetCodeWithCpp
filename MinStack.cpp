#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        allStack.push(x);
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
    
    void pop() {
        if (allStack.top() == minStack.top())
        {
            minStack.pop();
        }
        allStack.pop();
    }
    
    int top() {
        return allStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> allStack;
    stack<int> minStack;
};