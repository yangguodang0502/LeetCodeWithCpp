# ��ջʵ�ֶ���
## ��Ŀ
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

## ���
### �㷨����
1. ��������ջʵ�֣�����ջ������ջ
2. push��ʱ���Ƚ�����ջ��Ԫ��ȫ����������ջ���ٽ�Ԫ�ؼ�������ջ���������ջȫ��Ԫ�ؼ�������ջ
3. pop��ʱ��ȡ����ջ�Ķ���Ԫ�ز��Ƴ�ջ��
4. peek��������ջ�Ķ���Ԫ��
5. empty��������ջ�Ƿ�Ϊ��
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�pushΪO(n)��������ΪO(1)
+ �ռ临�Ӷȣ�O(n)��nΪջ�Ĵ�С
### Դ��
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