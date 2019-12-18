#define NULL nullptr

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void findRec(TreeNode* node, int& res, bool& find, int& i, int& k) {
        if (node == NULL || find) 
            return;
        findRec(node->left, res, find, i, k);
        if (++i == k)
        {
            res = node->val;
            find = true;
            return;
        }
        findRec(node->right, res, find, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        bool find = false;
        int res = -1;
        int i = 0;
        findRec(root, res, find, i, k);
        return res;
    }
};