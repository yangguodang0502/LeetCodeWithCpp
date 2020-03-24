#define NULL nullptr

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        lowestCommonAncestorRecursive(root, p, q, result);
        return result;
    }

    bool lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result)
    {
        if (root == NULL)
            return false;

        int left = lowestCommonAncestorRecursive(root->left, p, q, result) ? 1 : 0;
        int right = lowestCommonAncestorRecursive(root->right, p, q, result) ? 1 : 0;
        int cur = (root == p || root == q) ? 1 : 0;

        if (cur + left + right >= 2)
        {
            result = root;
        }

        return cur + left + right > 0;
    }
};