#define NULL nullptr

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
        if (root != NULL) {
            connectTwo(root->left, root->right);
        }
        return root;
    }

    void connectTwo(Node* left, Node* right) {
        if (left == NULL || right == NULL) {
            return;
        }

        left->next = right;

        connectTwo(left->left, left->right);
        connectTwo(right->left, right->right);
        connectTwo(left->right, right->left);
    }
};