# ��������������
## ��Ŀ
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.

## ���
### �㷨����
1. ����ݹ麯�������ж����������Ƿ�Գ�
2. ��������ӽڵ㶼Ϊ�շ���true
3. ��������ӽڵ���һ��Ϊ�շ���false
4. ��������ӽڵ��ֵ����ȷ���false
5. �ݹ��ж������������ӽڵ�������������ӽڵ��Ƿ�Գ�
   �������������ӽڵ�������������ӽڵ��Ƿ�Գ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջ���ö���ռ�
### Դ��
```C++ []
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetricRecursive(root->left, root->right);
    }

    bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        
        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;
        
        return isSymmetricRecursive(left->right, right->left)
            && isSymmetricRecursive(left->left, right->right);
    }
};