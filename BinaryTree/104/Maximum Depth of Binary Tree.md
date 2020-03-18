# 二叉树的最大深度
## 题目
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

## 题解
### 算法分析
1. 使用自底向上的递归方式
2. 如果root为空返回0
3. 否则递归计算左子树的深度leftDepth和右子树的深度rightDepth
4. 返回max(leftDepth, rightDepth) + 1
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈暂用额外空间
### 源码
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};