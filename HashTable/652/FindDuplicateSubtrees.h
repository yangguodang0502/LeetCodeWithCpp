#include <vector>
#include <unordered_map>

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
    string recursive(TreeNode* node, unordered_map<string, int>& hashMap, vector<TreeNode*>& results)
    {
        if (node == NULL)
            return "#";

        string str = to_string(node->val) + recursive(node->left, hashMap, results) + recursive(node->right, hashMap, results);
        hashMap[str]++;

        if (hashMap[str] == 2)
            results.push_back(node);
        
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> results;
        unordered_map<string, int> hashMap;
        recursive(root, hashMap, results);
        return results;
    }
};