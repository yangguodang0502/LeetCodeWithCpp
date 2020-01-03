#define NULL nullptr

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