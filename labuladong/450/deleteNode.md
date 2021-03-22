# Delete Node in a BST
## 题目
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?

 

Example 1:

![](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

![](https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg)

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105

## 题解
### 算法分析
1. 判断当前节点值和查找值val大小
2. 如果val小于当前节点值，递归查找左子树
3. 如果val大于当前节点值，递归查找右子树
4. 如果相等，如果左子树为空，返回右子节点
5. 如果右子树为空，返回左子节点
6. 否则查找右子树的最小节点，替换当前节点值为最小节点，递归删除右子数中的最小节点
7. 返回根节点
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* node = getMin(root->right);
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node) {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
};