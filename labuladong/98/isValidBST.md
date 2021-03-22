# Validate Binary Search Tree
## 题目
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

Input: root = [2,1,3]
Output: true

Example 2:

![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

## 题解
### 算法分析
1. 使用min，max记录当前最小值节点和最大值节点
2. 遍历左子树时，如果当前节点值大于max节点，返回false
3. 遍历右子树时，如果当前节点值小于min节点，返回false
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) {
            return true;
        }

        if (min != nullptr && root->val <= min->val) {
            return false;
        }
         
        if (max != nullptr && root->val >= max->val) {
            return false;
        }

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};