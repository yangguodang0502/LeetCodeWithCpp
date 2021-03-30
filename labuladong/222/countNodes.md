# Count Complete Tree Nodes
## 题目
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
 

Follow up: Traversing the tree to count the number of nodes in the tree is an easy solution but with O(n) complexity. Could you find a faster algorithm?

## 题解
### 算法分析
1. 统计左子树和右子树的深度
2. 如果深度相等，递归遍历右子树深度加上左子树深度的2次幂
3. 否则递归遍历左子树深度加上右子树深度的2次幂
### 复杂度分析
+ 时间复杂度：O(logn*logn)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int hl = 0;
        int hr = 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while (l != nullptr)
        {
            hl++;
            l = l->left;     
        }
        while (r != nullptr)
        {
            hr++;
            r = r->left;     
        }        
        if (hl == hr) {
            return countNodes(root->right) + (1 << hl);
        } else {
            return countNodes(root->left) +  (1 << hr);
        }
    }
};