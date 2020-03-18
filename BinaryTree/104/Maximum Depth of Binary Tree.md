# ��������������
## ��Ŀ
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

## ���
### �㷨����
1. ʹ���Ե����ϵĵݹ鷽ʽ
2. ���rootΪ�շ���0
3. ����ݹ���������������leftDepth�������������rightDepth
4. ����max(leftDepth, rightDepth) + 1
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջ���ö���ռ�
### Դ��
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};