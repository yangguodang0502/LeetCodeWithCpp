#define NULL nullptr

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