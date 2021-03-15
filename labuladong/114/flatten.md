# Flatten Binary Tree to Linked List
## 题目
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:

![](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0] 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

## 题解
### 算法分析
1. flatten(root.left)
2. flatten(root.right)
3. tmp = root.left
4. root.right = root.left
4. while(p) p = root.right
5. p.right = tmp
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* p = root;
        while (p->right != nullptr)
        {
            p = p->right;
        }
        p->right = tmp;
    }
};