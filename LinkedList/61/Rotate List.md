# 旋转链表
## 题目
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

## 题解
### 算法分析
1. 将尾节点指向头节点形成环
2. 根据下标i = n - k % n - 1找到新的尾节点和头节点
3. 将新的尾节点的next置为空
4. 返回新的头节点
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode* oldTail = head;
        int n = 1;
        while (oldTail->next != NULL)
        {
            oldTail = oldTail->next;
            n++;
        }
        oldTail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < n - k % n - 1; i++)
        {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};