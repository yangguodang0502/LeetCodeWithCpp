# ɾ������ĵ�����N���ڵ�
## ��Ŀ
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

## ���
### �㷨����
1. �趨�ڱ��ڵ㲢��next�ڵ�ָ��ͷ�ڵ㣬�������Դ���ͷ�ڵ㱻ɾ�������
2. �趨��ָ��ָ��ͷ�ڵ㣬��ָ��ָ���ڱ��ڵ�
3. ��ָ��ÿ��ǰ��һ���ڵ�ֱ��Ϊ��
4. ����ָ���߹�n��֮����ָ�뿪ʼͬ��ǰ��
5. �����ָ��ڵ����һ�ڵ㼴ΪҪɾ���Ľڵ㣬ɾ���ýڵ�
6. �����ڱ�����һ�ڵ�
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