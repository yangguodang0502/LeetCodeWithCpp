#define NULL nullptr

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode* oldTail = head;
        int n = 1;
        while (oldTail->next != NULL)
        {
            oldTail = oldTail->next;
            n++;
        }
        oldTail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < n - k % n - 1; i++)
        {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};