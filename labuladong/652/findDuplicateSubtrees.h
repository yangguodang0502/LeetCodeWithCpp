#include <vector>
#include <unordered_map>

using namespace std;

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> trees;
        traverseTree(root, trees, res);
        return res;
    }

    string traverseTree(TreeNode* root, unordered_map<string, int>& trees, vector<TreeNode*>& res) {
        if (root == nullptr) {
            return "#";
        }

        string left = traverseTree(root->left, trees, res);
        string right = traverseTree(root->right, trees, res);
        string str = left + "," + right + ',' + to_string(root->val);

        if (trees[str] == 1) {
            res.push_back(root);
        }
        trees[str]++;

        return str;
    }
};