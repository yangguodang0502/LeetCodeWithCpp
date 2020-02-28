# ��ż����
## ��Ŀ
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

## ���
### �㷨����
1. Ŀ���ǽ��±�0,1,...,n����ת��Ϊ0,2,...,1,3,...����
2. �趨nodeָ��head������ǰ�ڵ��±�i=0��ż���ڵ�evenNode=NULL������ͷ�ڵ�oddHead=NULL�������ڵ�oddNode=NULL
3. ����nodeֱ��nodeΪ��, i++
4. ���iΪż���������evenNodeΪ����evenNode=node����eventNode->next=node, eventNode=eventNode->next
5. ���iΪ�����������oddNodeΪ����oddHead=oddNode=node����oddNode->next=node, oddNode=oddNode->next
6. ѭ�����������evenNode��Ϊ����oddHead��Ϊ����evenNode->next=oddHead
7. ����head
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* node = head;
        ListNode* evenNode = NULL;
        ListNode* oddHead = NULL;
        ListNode* oddNode = NULL;
        int i = 0;

        while (node != NULL)
        {
            if (i++ % 2 == 0)
            {
                if (evenNode == NULL)
                {
                    evenNode = node;
                }
                else
                {
                    evenNode->next = node;
                    evenNode = evenNode->next;
                }
            }
            else
            {
                if (oddNode == NULL)
                {
                    oddHead = oddNode = node;
                }
                else
                {
                    oddNode->next = node;
                    oddNode = oddNode->next;
                }
            }

            node = node->next;
        }
        
        if (evenNode != NULL && oddHead != NULL)
        {
            evenNode->next = oddHead;
            oddNode->next = NULL;
        }

        return head;
    }
};