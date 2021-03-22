# Insert into a Binary Search Tree
## 题目
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:

![](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

![](https://assets.leetcode.com/uploads/2020/10/05/bst.jpg)

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.

## 题解
### 算法分析
1. 判断当前节点值和查找值val大小
2. 如果val小于当前节点值，如果左子节点为空则添加插入到左子节点，否则查找左子树
3. 如果val大于当前节点值，如果右子节点为空则添加插入到左子节点，否则查找右子树
4. 返回根节点
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* node = root;
        while (node != nullptr)
        {
            if (val < node->val) {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }
        return root;
    }
};