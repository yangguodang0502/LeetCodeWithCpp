# Flatten Nested List Iterator
## 题目

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].

## 题解
### 算法分析
1. 使用队列存储待遍历节点
2. hasNext()：遍历队列，如果队首是列表节点，逆序遍历列表将其节点加入队首
3. next()：返回队首节点的值，并将该节点出队
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class NestedIterator {
public:
    deque<NestedInteger> q;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++)
        {
            q.push_back(nestedList[i]);
        }        
    }
    
    int next() {
        int val = q.front().getInteger();
        q.pop_front();
        return val;
    }
    
    bool hasNext() {
        while (!q.empty() && !q.front().isInteger()) {
            vector<NestedInteger> ls = q.front().getList();
            q.pop_front();
            for (int i = ls.size() - 1; i >= 0; i--)
            {
                q.push_front(ls[i]);              
            }
        }
        return !q.empty();
    }
};