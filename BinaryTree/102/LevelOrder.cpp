#include <vector>
#include <queue>
#include <cstddef>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        vector<int> temp;

        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (node != NULL)
            {
                temp.push_back(node->val);

                if (node->left != NULL)
                {
                    nodeQueue.push(node->left);
                }

                if (node->right != NULL)
                {
                    nodeQueue.push(node->right);
                }                
            }
            else
            {
                result.push_back(temp);
                temp.clear();

                if (!nodeQueue.empty())
                    nodeQueue.push(NULL);
            }
        }        

        return result;
    }
};