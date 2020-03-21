# 路径总和
## 题目
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

## 题解
### 算法分析
1. 使用递归，sum从根节点开始往叶子节点一路递减，最后判断是否为0
2. 如果root为空返回false
3. sum -= root->val
4. 如果root的左右子节点都为空，返回sum是否为0
5. 否则递归调用左子树和右子树，如果任意一个结果为true则返回true
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈暂用额外空间
### 源码
```C++ []
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        sum -= root->val;

        if (root->left == NULL && root->right == NULL)   
            return sum == 0;

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};