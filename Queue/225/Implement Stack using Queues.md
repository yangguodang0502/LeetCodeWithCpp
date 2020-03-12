# 用队列实现栈
## 题目
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

## 题解
### 算法分析
1. 利用两个队列实现，正式队列和临时队列
2. push的时候将元素加入正式队列队尾
3. pop的时候先将正式队列除了队尾元素的其他元素依次加入临时队列，取正式队列队首元素并出队，
   将临时队列的所有元素依次加入正式队列
4. top返回正式队列队尾元素
5. empty返回正式队列是否为空
### 复杂度分析
+ 时间复杂度：pop为O(n)，其他都为O(1)
+ 空间复杂度：O(n)，n为队列的大小
### 源码
```C++ []
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        mQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (mQueue.size() > 1)
        {
            mTempQueue.push(mQueue.front());
            mQueue.pop();
        }
        
        int ret = mQueue.front();
        mQueue.pop();

        while (!mTempQueue.empty())
        {
            mQueue.push(mTempQueue.front());
            mTempQueue.pop();
        }
        
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return mQueue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mQueue.empty();
    }

private:
    queue<int> mQueue;
    queue<int> mTempQueue;
};