# 奇偶链表
## 题目
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

## 题解
### 算法分析
1. 目标是将下标0,1,...,n排列转化为0,2,...,1,3,...排列
2. 设定node指向head，链表当前节点下标i=0，偶数节点evenNode=NULL，奇数头节点oddHead=NULL，奇数节点oddNode=NULL
3. 遍历node直到node为空, i++
4. 如果i为偶数，则如果evenNode为空则evenNode=node否则eventNode->next=node, eventNode=eventNode->next
5. 如果i为奇数，则如果oddNode为空则oddHead=oddNode=node否则oddNode->next=node, oddNode=oddNode->next
6. 循环结束后，如果evenNode不为空且oddHead不为空则evenNode->next=oddHead
7. 返回head
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