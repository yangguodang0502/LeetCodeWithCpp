# 01 矩阵
## 题目
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

## 题解
### 算法分析
1. 定义二维数组result，如果root为空返回result
2. 定义队列存储待遍历的节点，将root入队，将NULL入队用于表示分层
3. 定义数组temp存储每层节点值
4. 遍历队列直到为空，出队队首节点node
5. 如果node不为空，将node->val加入数组，将node的左右不为空的子节点加入队列
6. 否则将temp加入result，清空temp，如果队列不为空则将NULL入队
7. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n+m), n为树节点个数，m不树的层数
+ 空间复杂度：O(n+m)，队列暂用额外空间
### 源码
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