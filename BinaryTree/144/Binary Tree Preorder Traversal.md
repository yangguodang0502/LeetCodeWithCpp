# 01 矩阵
## 题目
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?

## 题解
### 算法分析
1. 定义数组result用于存储结果
2. 定义栈用于存储待遍历节点，将根节点入栈
3. 遍历栈直到为空，出栈栈顶元素node
4. 将node.val加入result
5. 如果右子节点不为空则入栈，如果左子节点不为空则入栈
6. 返回result
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，栈暂用额外空间
### 源码
```C++ []
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty())
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.push_back(node->val);

            if (node->right != NULL)
                nodeStack.push(node->right);

            if (node->left != NULL)
                nodeStack.push(node->left);
        }
        
        return result;
    }
};