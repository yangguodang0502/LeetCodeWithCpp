#include <cstddef>
#include <vector>
#include <stack>
#include <set>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root ==  NULL)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.insert(result.begin(), node->val);

            if (node->left != NULL)
                nodeStack.push(node->left);  

            if (node->right != NULL)
                nodeStack.push(node->right);         
        }
        
        return result;
    }
};