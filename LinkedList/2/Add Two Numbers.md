# �������
## ��Ŀ
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

## ���
### �㷨����
1. ʹ��˫ָ�룬ʹ�ñ�־λadd��ʾ�Ƿ��λ
2. ��l1��l2ͬ��ǰ����ֱ����Ϊ��
3. ����sum = l1->val + l2->val + add��add = sum < 10 ? 0 : 1 
### ���Ӷȷ���
+ ʱ�临�Ӷ�: O(n), nΪ����l1��l2����󳤶�
+ �ռ临�Ӷȣ�O(1)
### Դ��
```C++ []
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL;
        ListNode* node = NULL;
        int add = 0;
        int sum;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
                sum = l2->val + add;
            else if (l2 == NULL)
                sum = l1->val + add;
            else
                sum = l1->val + l2->val + add;
            if (sum >= 10)
            {
                sum = sum - 10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            
            if (node == NULL)
            {
                node = new ListNode(sum);
                root = node;
            }
            else
            {
                node->next = new ListNode(sum);
                node = node->next;
            }
            
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (add != 0)
        {
            node->next = new ListNode(add);
        }
        return root;
    }
};