#define NULL nullptr

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flattenRecusive(Node* head)
    {
        if (head == NULL)
            return NULL;

        Node* nextNode = head->next;
        Node* childNode = head->child;

        if (nextNode == NULL && childNode == NULL)
        {
            return head;
        }

        Node* node = flattenRecusive(childNode);

        if (node != NULL)
        {
            head->next = childNode;
            childNode->prev = head;
            node->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = node;
            head->child = NULL;
        }

        return nextNode != NULL ? flattenRecusive(nextNode) : node;
    }

    Node* flatten(Node* head) {
        flattenRecusive(head);
        return head;
    }
};