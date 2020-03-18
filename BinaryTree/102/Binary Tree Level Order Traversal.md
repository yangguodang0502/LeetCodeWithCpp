# 01 ����
## ��Ŀ
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

## ���
### �㷨����
1. �����ά����result�����rootΪ�շ���result
2. ������д洢�������Ľڵ㣬��root��ӣ���NULL������ڱ�ʾ�ֲ�
3. ��������temp�洢ÿ��ڵ�ֵ
4. ��������ֱ��Ϊ�գ����Ӷ��׽ڵ�node
5. ���node��Ϊ�գ���node->val�������飬��node�����Ҳ�Ϊ�յ��ӽڵ�������
6. ����temp����result�����temp��������в�Ϊ����NULL���
7. ��󷵻�result
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n+m), nΪ���ڵ������m�����Ĳ���
+ �ռ临�Ӷȣ�O(n+m)���������ö���ռ�
### Դ��
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        vector<int> temp;

        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (node != NULL)
            {
                temp.push_back(node->val);

                if (node->left != NULL)
                {
                    nodeQueue.push(node->left);
                }

                if (node->right != NULL)
                {
                    nodeQueue.push(node->right);
                }                
            }
            else
            {
                result.push_back(temp);
                temp.clear();

                if (!nodeQueue.empty())
                    nodeQueue.push(NULL);
            }
        }        

        return result;
    }
};