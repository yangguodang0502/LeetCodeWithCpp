# 最小栈
## 题目
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

## 题解
### 算法分析
1. 使用两个栈，allStack存储所有元素，minStack存储所有最小元素
2. 入栈时，元素加入allStack，并判断minStack为空或者元素小于等于栈顶元素，则入栈
3. 出栈时，判断allStack的栈顶元素和minStack相等，则minStack出栈，最后allStack出栈
4. 获取栈顶元素，返回allStack栈顶元素
5. 获取最小值，返回minStack栈顶元素
### 复杂度分析
+ 时间复杂度：O(1)
+ 空间复杂度：O(n)
### 源码
```C++ []
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