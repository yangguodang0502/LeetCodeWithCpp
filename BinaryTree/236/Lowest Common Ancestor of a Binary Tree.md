# �������������������
## ��Ŀ
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).��

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)
 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

## ���
### �㷨����
1. �������ڵ㣬ʹ�õݹ麯�����������ӽڵ�
2. ����ڵ�Ϊ�շ���false
3. ����left�洢�������ı������������right�洢�������ı������
4. ����cur�жϵ�ǰ�ڵ��Ƿ����p����q�ڵ㣬����ȸ�ֵ1����ֵ0
5. ���cur + left + right >= 2���򽫵�ǰ�ڵ㸳ֵ������ڵ�
6. �ж�cur + left + right �Ƿ����0���������0��ʾ����Ŀ��ڵ㷵��true���򷵻�false
7. ��󷵻ؽ���ڵ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջռ�ÿռ�
### Դ��
```C++ []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        lowestCommonAncestorRecursive(root, p, q, result);
        return result;
    }

    bool lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result)
    {
        if (root == NULL)
            return false;

        int left = lowestCommonAncestorRecursive(root->left, p, q, result) ? 1 : 0;
        int right = lowestCommonAncestorRecursive(root->right, p, q, result) ? 1 : 0;
        int cur = (root == p || root == q) ? 1 : 0;

        if (cur + left + right >= 2)
        {
            result = root;
        }

        return cur + left + right > 0;
    }
};