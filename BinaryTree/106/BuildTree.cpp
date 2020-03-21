#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postRootIndex = postorder.size() - 1;

        map<int, int> inorderMap;
        int index = 0;
        for (auto &&val : inorder)
        {
            inorderMap.insert(make_pair(val, index++));
        }
        
        return buildTreeRecursive(0, postorder.size() - 1, postRootIndex, postorder, inorderMap);
    }

    TreeNode* buildTreeRecursive(int leftIndex, int rightIndex
        , int& postorderIndex, vector<int>& postorder, map<int, int>& inorderMap) {
            if (leftIndex > rightIndex)
                return NULL;

            int val = postorder[postorderIndex];
            TreeNode* root = new TreeNode(val);

            --postorderIndex;
            int index = inorderMap[val];
            root->right = buildTreeRecursive(index + 1, rightIndex, postorderIndex, postorder, inorderMap);
            root->left = buildTreeRecursive(leftIndex, index - 1, postorderIndex, postorder, inorderMap);

            return root;
    }
};