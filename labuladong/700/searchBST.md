# Search in a Binary Search Tree
## 题目
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
 

Example 1:

![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:

![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107

## 题解
### 算法分析
1. 判断当前节点值和查找值val大小
2. 如果val小于当前节点值，返回查找左子树
3. 如果val大于当前节点值，返回查找右子树
4. 返回根节点
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        } else if (val > root->val) {
            return searchBST(root->right, val);
        }
        return root;
    }
};