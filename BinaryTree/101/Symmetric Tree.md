# 二叉树的最大深度
## 题目
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.

## 题解
### 算法分析
1. 定义递归函数用于判断左右子树是否对称
2. 如果左右子节点都为空返回true
3. 如果左右子节点有一个为空返回false
4. 如果左右子节点的值不想等返回false
5. 递归判断左子树的右子节点和右子树的左子节点是否对称
   且左子树的左子节点和右子树的右子节点是否对称
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈暂用额外空间
### 源码
```C++ []
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetricRecursive(root->left, root->right);
    }

    bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        
        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;
        
        return isSymmetricRecursive(left->right, right->left)
            && isSymmetricRecursive(left->left, right->right);
    }
};