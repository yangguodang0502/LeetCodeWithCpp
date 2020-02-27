# 环形链表 II
## 题目
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)


 

Follow-up:
Can you solve it without using extra space?

## 题解
### 算法分析
1. 设定指针node指向头节点，使用哈希表存储已访问过的节点
2. 遍历链表，node每次前进一个节点
3. 判断node是否已访问过, 如果已访问过则输出node，否则输出NULL
### 复杂度分析
+ 时间复杂度: O(n), n为链表节点个数
+ 空间复杂度：O(n)
### 源码
```C++ []
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *node = head;
        set<ListNode*> visitedNodes;
        while (node != NULL)
        {
            if (visitedNodes.find(node) != visitedNodes.end())
            {
                return node;
            }
            visitedNodes.insert(node);
            node = node->next;
        }
        return NULL;
    }
};