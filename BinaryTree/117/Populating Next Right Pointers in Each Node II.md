# ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
## ��Ŀ
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

## ���
### �㷨����
1. ����firstNode�洢ÿ����ʼ�ڵ㣬��ʼ��Ϊroot
2. ����firstNodeֱ��Ϊ��
3. ����node���ڱ����ò����еĽڵ��ʼ��ΪfirstNode
4. ����newFirstNode���ڼ�¼��һ����ʼ�ڵ��ʼ��ΪNULL
5. ����preNode���ڼ�¼ǰ�ýڵ��ʼ��ΪNULL
6. ����nodeֱ��Ϊ��
7. ���node�����ӽڵ㲻Ϊ�գ����ж�newFirstNode�Ƿ�Ϊ�գ�Ϊ�ս��ýڵ㸳ֵ��newFirstNode
   �ж�preNode�Ƿ�ǿգ��ǿս��ýڵ㸳ֵ��preNode->next�����node�����ӽڵ�Ҳ��Ϊ�գ�
   �������ӽڵ��������������ҽ�preNode��Ϊ���ӽڵ㣬������Ϊ���ӽڵ�
8. �������node�����ӽڵ㲻Ϊ�գ����ж�newFirstNode�Ƿ�Ϊ�գ�Ϊ�ս��ýڵ㸳ֵ��newFirstNode
   �ж�preNode�Ƿ�ǿգ��ǿս��ýڵ㸳ֵ��preNode->next����preNode��Ϊ���ӽڵ�
9. ��nodeָ����һ�ڵ㣬������6��
10. ��newFirstNode��ֵ��firstNode��������2��
11. ��󷵻�root
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(1)
### Դ��
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