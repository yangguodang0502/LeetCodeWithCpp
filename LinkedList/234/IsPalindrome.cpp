#define NULL nullptr

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* findMidNode(ListNode* head)
    {
        ListNode* slowNode = head;
        ListNode* fastNode = head;

        while (fastNode->next != NULL && fastNode->next->next != NULL)
        {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        
        return slowNode;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while (node != NULL)
        {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }      

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;

        ListNode* midNode = findMidNode(head);
        ListNode* secondNode = reverseList(midNode->next);
        ListNode* firstNode = head;

        while (secondNode != NULL)
        {
            if (secondNode->val != firstNode->val)
            {
                return false;
            }

            secondNode = secondNode->next;
            firstNode = firstNode->next;
        }
        
        return true;
    }
};