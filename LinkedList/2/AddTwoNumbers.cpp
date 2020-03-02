/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL nullptr

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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