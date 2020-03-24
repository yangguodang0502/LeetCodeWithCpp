# 二叉树的最近公共祖先
## 题目
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)
 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

## 题解
### 算法分析
1. 定义结果节点，使用递归函数遍历左右子节点
2. 如果节点为空返回false
3. 定义left存储左子树的遍历结果，定义right存储右子树的遍历结果
4. 定义cur判断当前节点是否等于p或者q节点，如果等赋值1否则赋值0
5. 如果cur + left + right >= 2，则将当前节点赋值给结果节点
6. 判断cur + left + right 是否大于0，如果大于0表示存在目标节点返回true否则返回false
7. 最后返回结果节点
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈占用空间
### 源码
```C++ []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        lowestCommonAncestorRecursive(root, p, q, result);
        return result;
    }

    bool lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result)
    {
        if (root == NULL)
            return false;

        int left = lowestCommonAncestorRecursive(root->left, p, q, result) ? 1 : 0;
        int right = lowestCommonAncestorRecursive(root->right, p, q, result) ? 1 : 0;
        int cur = (root == p || root == q) ? 1 : 0;

        if (cur + left + right >= 2)
        {
            result = root;
        }

        return cur + left + right > 0;
    }
};