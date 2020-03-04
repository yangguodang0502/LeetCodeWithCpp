#include<map>

using namespace std;

#define NULL nullptr

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        map<Node*, Node*>::iterator iter = nodeMap.find(head);
        if (iter != nodeMap.end())
            return iter->second;

        Node* node = new Node(head->val);
        nodeMap.insert(pair<Node*, Node*>(head, node));

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
private:
    map<Node*, Node*> nodeMap;
};