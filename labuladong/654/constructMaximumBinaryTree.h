#include <vector>

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int index = end;
        int max = nums[end];
        for (int i = start; i < end; i++) {
            if (nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }
        
        TreeNode* root = new TreeNode(max);
        root->left = construct(nums, start, index - 1);
        root->right = construct(nums, index + 1, end);

        return root;
    }
};