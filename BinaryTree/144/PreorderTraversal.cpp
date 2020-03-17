#include <cstddef>
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.push_back(node->val);

            if (node->right != NULL)
                nodeStack.push(node->right);

            if (node->left != NULL)
                nodeStack.push(node->left);
        }
        
        return result;
    }
};