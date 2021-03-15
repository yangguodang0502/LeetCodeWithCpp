#  Invert Binary Tree
## 题目
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

## 题解
### 算法分析
1. invertTree(root.left)
2. invertTree(root.right)
3. swap(root.left, root.right)
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};