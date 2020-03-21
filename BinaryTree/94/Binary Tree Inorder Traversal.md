# ���������������
## ��Ŀ
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

## ���
### �㷨����
1. ʹ�õݹ�node�ڵ㣬���ѽ�����������result��
2. ���nodeΪ�գ��򷵻�NULL
3. ���node�����ӽڵ㲻Ϊ�գ��ݹ����ӽڵ�
4. ��node��val��������
5. ���node�����ӽڵ㲻Ϊ�գ��ݹ����ӽڵ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)��nΪ���������
+ �ռ临�Ӷȣ�O(n)���ݹ����ջռ�ÿռ�
### Դ��
```C++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }

    void inorderRecursive(TreeNode* node, vector<int>& result) {
        if (node == NULL)
            return;

        if (node->left != NULL)
            inorderRecursive(node->left, result);
            
        result.push_back(node->val);

        if (node->right != NULL)
            inorderRecursive(node->right, result);
    }
};