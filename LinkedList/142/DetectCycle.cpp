#include<set>

#define NULL nullptr

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *node = head;
        set<ListNode*> visitedNodes;
        while (node != NULL)
        {
            if (visitedNodes.find(node) != visitedNodes.end())
            {
                return node;
            }
            visitedNodes.insert(node);
            node = node->next;
        }
        return NULL;
    }
};