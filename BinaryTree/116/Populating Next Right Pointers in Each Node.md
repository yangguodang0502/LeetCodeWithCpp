# ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
## ��Ŀ
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

## ���
### �㷨����
1. ʹ�ò�α�����������д洢�����ʵĽڵ�
2. ��root�ڵ���ӣ���NULL������ڷָ���
3. ����preNode=NULL���ڴ洢��һ���ڵ�
4. ѭ����������ֱ��Ϊ�գ����Ӷ���Ԫ��node
5. ���preNodeΪ�գ���preNode=node������preNode��nextָ��node������node��ֵ��preNode
6. ���node��Ϊ�գ���node�ķǿ������ӽڵ�ֱ�������
7. ����������в�Ϊ�ս�NULL�������
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)������ռ�ö���ռ�
### Դ��
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