#include <cstddef>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
            
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        Node* preNode = NULL;

        while (!nodeQueue.empty())
        {
            Node* node = nodeQueue.front();
            nodeQueue.pop();

            if (preNode == NULL)
            {
                preNode = node;
            }
            else
            {
                preNode->next = node;
                preNode = node;
            }

            if (node != NULL)   
            {
                if (node->left != NULL)
                {
                    nodeQueue.push(node->left);
                }

                if (node->right != NULL)
                {
                    nodeQueue.push(node->right);
                }
            }
            else if (!nodeQueue.empty())
            {
                nodeQueue.push(NULL);
            }      
        }        

        return root;
    }
};