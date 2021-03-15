# Populating Next Right Pointers in Each Node
## 题目
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:

![](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.

## 题解
### 算法分析
1. connectTwo(root.left, root.right)
2. left.next = right
3. connectTwo(left.left, left.right)
4. connectTwo(right.left, right.right)
5. connectTwo(left.right, right.left)
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    Node* connect(Node* root) {
        if (root != NULL) {
            connectTwo(root->left, root->right);
        }
        return root;
    }

    void connectTwo(Node* left, Node* right) {
        if (left == NULL || right == NULL) {
            return;
        }

        left->next = right;

        connectTwo(left->left, left->right);
        connectTwo(right->left, right->right);
        connectTwo(left->right, right->left);
    }
};