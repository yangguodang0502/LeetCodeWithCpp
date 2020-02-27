# 环形链表
## 题目
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

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

 

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

## 题解
### 算法分析
1. 使用快慢指针，初始时慢指针指向头节点，快指针指向头指针的下一节点
2. 慢指针每次移动一个节点，快指针每次移动两个节点
3. 循环判断快慢指针是否相等，直到快指针或者快指针的下一节点为空
### 复杂度分析
+ 时间复杂度: O(n), n为链表节点个数
+ 空间复杂度：O(1)
### 源码
```C++ []
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *first = head;
        ListNode *second = head->next;
        while (second != NULL && second->next != NULL)
        {
            if (first == second)
                return true;
            first = first->next;
            second = second->next->next;
        }
        return false;
    }
};