# �������ĺ������
## ��Ŀ
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?

## ���
### �㷨����
1. ��������result���ڴ洢���
2. ����ջ���ڴ洢�������ڵ㣬�����ڵ���ջ
3. ����ջֱ��Ϊ�գ���ջջ��Ԫ��node
4. ��node.val���뵽resultͷ��
5. ������ӽڵ㲻Ϊ������ջ��������ӽڵ㲻Ϊ������ջ
6. ����result
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)��ջ���ö���ռ�
### Դ��
```C++ []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root ==  NULL)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.insert(result.begin(), node->val);

            if (node->left != NULL)
                nodeStack.push(node->left);  

            if (node->right != NULL)
                nodeStack.push(node->right);         
        }
        
        return result;
    }
};