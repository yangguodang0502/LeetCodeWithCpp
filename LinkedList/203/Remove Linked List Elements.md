# �Ƴ�����Ԫ��
## ��Ŀ
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

## ���
### �㷨����
1. ����ڱ��ڵ�sentryNode������һ�ڵ�ָ��ͷ�ڵ�
2. �趨nodeָ��sentryNode
3. ����node��һ�ڵ�ֱ��Ϊ��
4. ���node��һ�ڵ��ֵΪval����ɾ���ýڵ�
5. ����sentryNode����һ�ڵ�
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentryNode = new ListNode(-1);
        sentryNode->next = head;
        ListNode* node = sentryNode;
        
        while (node != NULL && node->next != NULL)
        {
            if (val == node->next->val)
            {
                node->next = node->next->next;
            }
            else
            {
                node = node->next;
            }       
        }
        
        return sentryNode->next;
    }
};