# 删除链表的倒数第N个节点
## 题目
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

## 题解
### 算法分析
1. 设定哨兵节点并将next节点指向头节点，这样可以处理头节点被删除的情况
2. 设定快指针指向头节点，慢指针指向哨兵节点
3. 快指针每次前进一个节点直到为空
4. 当快指针走过n步之后慢指针开始同步前进
5. 最后慢指针节点的下一节点即为要删除的节点，删除该节点
6. 返回哨兵的下一节点
### 复杂度分析
+ 时间复杂度：O(n)，n为链表长度
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;

        ListNode* sentry = new ListNode(-1);
        sentry->next = head;
        ListNode* first = head;
        ListNode* second = sentry;

        while (first != NULL)
        {
            first = first->next;
            if (n > 0)
            {
                --n;
            }
            else
            {
                second = second->next;
            }
        }

        second->next = second->next->next;

        return sentry->next;
    }
};