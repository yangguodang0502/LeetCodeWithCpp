# 反转链表
## 题目
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

## 题解
### 算法分析
1. 设定node指向头节点，设定pre指向node的前一节点，next指向node的下一节点
2. 遍历node指针直到为空，node的下一节点指向pre节点，pre指向node节点，node指向next节点
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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while (node != NULL)
        {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }      

        return pre;
    }
};