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
        Node* firstNode = root;

        while (firstNode != NULL)
        {
            Node* node = firstNode;
            Node* newFirstNode = NULL;
            Node* preNode = NULL;

            while (node != NULL)
            {
                if (node->left != NULL)
                {
                    if (newFirstNode == NULL)
                        newFirstNode = node->left;

                    if (preNode != NULL)
                        preNode->next = node->left;

                    if (node->right != NULL)
                    {
                        node->left->next = node->right;
                        preNode = node->right;
                    }
                    else
                    {
                        preNode = node->left;   
                    }
                }
                else if (node->right != NULL)
                {
                    if (newFirstNode == NULL)
                        newFirstNode = node->right;

                    if (preNode != NULL)
                        preNode->next = node->right;

                    preNode = node->right;
                }

                node = node->next;
            }
            
            firstNode = newFirstNode;
        }        

        return root;
    }
};