# 填充每个节点的下一个右侧节点指针 II
## 题目
Given a binary tree

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
![](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

## 题解
### 算法分析
1. 定义firstNode存储每层的最开始节点，初始化为root
2. 遍历firstNode直到为空
3. 定义node用于遍历该层所有的节点初始化为firstNode
4. 定义newFirstNode用于记录下一层的最开始节点初始化为NULL
5. 定义preNode用于记录前置节点初始化为NULL
6. 遍历node直到为空
7. 如果node的左子节点不为空，则判断newFirstNode是否为空，为空将该节点赋值给newFirstNode
   判断preNode是否非空，非空将该节点赋值给preNode->next，如果node的右子节点也不为空，
   将左右子节点链接起来，并且将preNode置为右子节点，否则置为左子节点
8. 否则如果node的右子节点不为空，则判断newFirstNode是否为空，为空将该节点赋值给newFirstNode
   判断preNode是否非空，非空将该节点赋值给preNode->next，将preNode置为右子节点
9. 将node指向下一节点，跳到第6步
10. 将newFirstNode赋值给firstNode，跳到第2步
11. 最后返回root
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    Node* connect(Node* root) {
        Node* firstNode = root;

        while (firstNode != NULL)
        {
            Node* node = firstNode;
            Node* newFirstNode = NULL;
            Node* preNode = NULL;

            while (node != NULL)
            {
                if (node->left != NULL)
                {
                    if (newFirstNode == NULL)
                        newFirstNode = node->left;

                    if (preNode != NULL)
                        preNode->next = node->left;

                    if (node->right != NULL)
                    {
                        node->left->next = node->right;
                        preNode = node->right;
                    }
                    else
                    {
                        preNode = node->left;   
                    }
                }
                else if (node->right != NULL)
                {
                    if (newFirstNode == NULL)
                        newFirstNode = node->right;

                    if (preNode != NULL)
                        preNode->next = node->right;

                    preNode = node->right;
                }

                node = node->next;
            }
            
            firstNode = newFirstNode;
        }        

        return root;
    }
};