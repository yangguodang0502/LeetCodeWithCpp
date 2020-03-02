# �ϲ�������������
## ��Ŀ
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

## ���
### �㷨����
1. ʹ��˫ָ��͵ݹ�
2. ��l1Ϊ�գ�����l2
3. ��l2Ϊ�գ�����l1
4. ��l1ֵС�ڵ���l2ֵ���ϲ�l1->next��l2�������������l1->next
5. ��֮��ϲ�l2->next��l1�������������l2->next
### ���Ӷȷ���
+ ʱ�临�Ӷ�: O(n), nΪ����l1��l2����̳���
+ �ռ临�Ӷȣ�O(n)
### Դ��
```C++ []
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};