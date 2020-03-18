# 二叉树的后序遍历
## 题目
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

## 题解
### 算法分析
1. 定义数组result用于存储结果
2. 定义栈用于存储待遍历节点，将根节点入栈
3. 遍历栈直到为空，出栈栈顶元素node
4. 将node.val插入到result头部
5. 如果左子节点不为空则入栈，如果右子节点不为空则入栈
6. 返回result
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，栈暂用额外空间
### 源码
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