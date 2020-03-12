#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }

    void inorderRecursive(TreeNode* node, vector<int>& result) {
        if (node == NULL)
            return;

        if (node->left != NULL)
            inorderRecursive(node->left, result);
            
        result.push_back(node->val);

        if (node->right != NULL)
            inorderRecursive(node->right, result);
    }
};