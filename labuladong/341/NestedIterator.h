#include <vector>
#include <queue>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

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

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */