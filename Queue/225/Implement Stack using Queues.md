# �ö���ʵ��ջ
## ��Ŀ
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

## ���
### �㷨����
1. ������������ʵ�֣���ʽ���к���ʱ����
2. push��ʱ��Ԫ�ؼ�����ʽ���ж�β
3. pop��ʱ���Ƚ���ʽ���г��˶�βԪ�ص�����Ԫ�����μ�����ʱ���У�ȡ��ʽ���ж���Ԫ�ز����ӣ�
   ����ʱ���е�����Ԫ�����μ�����ʽ����
4. top������ʽ���ж�βԪ��
5. empty������ʽ�����Ƿ�Ϊ��
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�popΪO(n)��������ΪO(1)
+ �ռ临�Ӷȣ�O(n)��nΪ���еĴ�С
### Դ��
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