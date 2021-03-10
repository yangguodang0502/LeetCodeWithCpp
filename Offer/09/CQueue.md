# 剑指 Offer 09. 用两个栈实现队列
## 题目

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

## 题解
### 算法分析
1. 定义left,right两个栈
2. 入队时将元素入left栈
3. 出队时将如果right栈不为空则将其栈顶元素出栈
4. 否则如果left栈为空返回-1
5. 否则遍历left栈将元素依次压入right栈
6. 将right栈顶元素出栈
### 复杂度分析
+ 时间复杂度：入队：O(1)，出队：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
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