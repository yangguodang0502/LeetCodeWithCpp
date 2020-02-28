# ��ת����
## ��Ŀ
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

## ���
### �㷨����
1. �趨nodeָ��ͷ�ڵ㣬�趨preָ��node��ǰһ�ڵ㣬nextָ��node����һ�ڵ�
2. ����nodeָ��ֱ��Ϊ�գ�node����һ�ڵ�ָ��pre�ڵ㣬preָ��node�ڵ㣬nodeָ��next�ڵ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)��nΪ������
+ �ռ临�Ӷȣ�O(1)
### Դ��
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