#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> m_left;
    stack<int> m_right;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        m_left.push(value);
    }
    
    int deleteHead() {
        if (!m_right.empty()) {
            int val = m_right.top();
            m_right.pop();
            return val;
        }
        if (m_left.empty()){
            return -1;
        }
        while (!m_left.empty())
        {
            int val = m_left.top();
            m_right.push(val);
            m_left.pop();
        }
        int val = m_right.top();
        m_right.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */