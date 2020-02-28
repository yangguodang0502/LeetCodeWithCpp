#define NULL nullptr

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