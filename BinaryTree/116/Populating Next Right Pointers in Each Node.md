# 填充每个节点的下一个右侧节点指针
## 题目
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:
![](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

## 题解
### 算法分析
1. 使用层次遍历，定义队列存储待访问的节点
2. 将root节点入队，将NULL入队用于分割层次
3. 定义preNode=NULL用于存储上一个节点
4. 循环遍历队列直到为空，出队队首元素node
5. 如果preNode为空，则preNode=node，否则preNode的next指向node，并将node赋值给preNode
6. 如果node不为空，将node的非空左右子节点分别加入队列
7. 否则如果队列不为空将NULL加入队列
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，队列占用额外空间
### 源码
```C++ []
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
            
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(NULL);
        Node* preNode = NULL;

        while (!nodeQueue.empty())
        {
            Node* node = nodeQueue.front();
            nodeQueue.pop();

            if (preNode == NULL)
            {
                preNode = node;
            }
            else
            {
                preNode->next = node;
                preNode = node;
            }

            if (node != NULL)   
            {
                if (node->left != NULL)
                {
                    nodeQueue.push(node->left);
                }

                if (node->right != NULL)
                {
                    nodeQueue.push(node->right);
                }
            }
            else if (!nodeQueue.empty())
            {
                nodeQueue.push(NULL);
            }      
        }        

        return root;
    }
};