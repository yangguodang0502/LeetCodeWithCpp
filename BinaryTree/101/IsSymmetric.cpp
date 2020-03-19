#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetricRecursive(root->left, root->right);
    }

    bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        
        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;
        
        return isSymmetricRecursive(left->right, right->left)
            && isSymmetricRecursive(left->left, right->right);
    }
};