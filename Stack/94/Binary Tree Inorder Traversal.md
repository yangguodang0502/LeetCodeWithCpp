# 二叉树的中序遍历
## 题目
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

## 题解
### 算法分析
1. 使用递归node节点，并把结果存放在数组result中
2. 如果node为空，则返回NULL
3. 如果node的左子节点不为空，递归左子节点
4. 将node的val加入数组
5. 如果node的右子节点不为空，递归右子节点
### 复杂度分析
+ 时间复杂度：O(n)，n为二叉树深度
+ 空间复杂度：O(n)，递归调用栈占用空间
### 源码
```C++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }

    void inorderRecursive(TreeNode* node, vector<int>& result) {
        if (node == NULL)
            return;

        if (node->left != NULL)
            inorderRecursive(node->left, result);
            
        result.push_back(node->val);

        if (node->right != NULL)
            inorderRecursive(node->right, result);
    }
};