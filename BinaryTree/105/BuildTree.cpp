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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRootIndex = 0;

        map<int, int> inorderMap;
        int index = 0;
        for (auto &&val : inorder)
        {
            inorderMap.insert(make_pair(val, index++));
        }
        
        return buildTreeRecursive(0, preorder.size() - 1, preRootIndex, preorder, inorderMap);
    }

    TreeNode* buildTreeRecursive(int leftIndex, int rightIndex
        , int& preorderIndex, vector<int>& preorder, map<int, int>& inorderMap) {
            if (leftIndex > rightIndex)
                return NULL;

            int val = preorder[preorderIndex];
            TreeNode* root = new TreeNode(val);

            ++preorderIndex;
            int index = inorderMap[val];
            root->left = buildTreeRecursive(leftIndex, index - 1, preorderIndex, preorder, inorderMap);
            root->right = buildTreeRecursive(index + 1, rightIndex, preorderIndex, preorder, inorderMap);
            
            return root;
    }
};