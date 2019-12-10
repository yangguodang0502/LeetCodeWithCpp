#define NULL nullptr

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        int sizeA = 0;
        while (nodeA != NULL)
        {
            nodeA = nodeA->next;
            ++sizeA;
        }

        ListNode *nodeB = headB;
        int sizeB = 0;
        while (nodeB != NULL)
        {
            nodeB = nodeB->next;
            ++sizeB;
        }

        if (nodeA != nodeB)
            return NULL;

        nodeA = headA;
        nodeB = headB;
        if (sizeA > sizeB)
        {
            int diff = sizeA - sizeB;
            while (diff > 0)
            {
                nodeA = nodeA-> next;
                --diff;
            }
        }
        else if (sizeA < sizeB)
        {
            int diff = sizeB - sizeA;
            while (diff > 0)
            {
                nodeB = nodeB->next;
                --diff;
            }            
        }

        while (nodeA != NULL && nodeB != NULL)
        {
            if (nodeA == nodeB)
                return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return NULL;
    }
};