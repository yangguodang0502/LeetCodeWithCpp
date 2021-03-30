struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int hl = 0;
        int hr = 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while (l != nullptr)
        {
            hl++;
            l = l->left;     
        }
        while (r != nullptr)
        {
            hr++;
            r = r->left;     
        }        
        if (hl == hr) {
            return countNodes(root->right) + (1 << hl);
        } else {
            return countNodes(root->left) +  (1 << hr);
        }
    }
};