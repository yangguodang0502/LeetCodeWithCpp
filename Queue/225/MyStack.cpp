#include <queue>

using namespace std;

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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */