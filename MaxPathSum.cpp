#include<algorithm>

using namespace std;

#define NULL nullptr

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxSum;
    int maxPathSumRecursive(TreeNode* node)
    {
        if (node == NULL)
            return 0;
       
        int left = max(maxPathSumRecursive(node->left), 0);
        int right = max(maxPathSumRecursive(node->right), 0);

        int subPath = node->val + left + right;
        maxSum = max(maxSum, subPath);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathSumRecursive(root);
        return maxSum;
    }
};