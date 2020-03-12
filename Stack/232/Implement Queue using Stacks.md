# 用栈实现队列
## 题目
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

## 题解
### 算法分析
1. 利用两个栈实现，正序栈和逆序栈
2. push的时候先将逆序栈的元素全部加入正序栈，再将元素加入正序栈，最后将正序栈全部元素加入逆序栈
3. pop的时候取逆序栈的顶部元素并推出栈顶
4. peek返回逆序栈的顶部元素
5. empty返回逆序栈是否为空
### 复杂度分析
+ 时间复杂度：push为O(n)，其他都为O(1)
+ 空间复杂度：O(n)，n为栈的大小
### 源码
```C++ []
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!mBackwardStack.empty())
        {
            mForwardStack.push(mBackwardStack.top());
            mBackwardStack.pop();
        }        
        
        mForwardStack.push(x);

        while (!mForwardStack.empty())
        {
            mBackwardStack.push(mForwardStack.top());
            mForwardStack.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = mBackwardStack.top();
        mBackwardStack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return mBackwardStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mBackwardStack.empty();
    }

private:
    stack<int> mBackwardStack;
    stack<int> mForwardStack;
};