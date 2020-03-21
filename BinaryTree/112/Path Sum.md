# ·���ܺ�
## ��Ŀ
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

## ���
### �㷨����
1. ʹ�õݹ飬sum�Ӹ��ڵ㿪ʼ��Ҷ�ӽڵ�һ·�ݼ�������ж��Ƿ�Ϊ0
2. ���rootΪ�շ���false
3. sum -= root->val
4. ���root�������ӽڵ㶼Ϊ�գ�����sum�Ƿ�Ϊ0
5. ����ݹ���������������������������һ�����Ϊtrue�򷵻�true
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջ���ö���ռ�
### Դ��
```C++ []
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        sum -= root->val;

        if (root->left == NULL && root->right == NULL)   
            return sum == 0;

        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};