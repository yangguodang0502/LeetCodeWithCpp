#include <stack>

using namespace std;

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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */