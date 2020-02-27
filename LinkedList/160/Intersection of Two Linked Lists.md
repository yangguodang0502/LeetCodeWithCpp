# 相交链表
## 题目
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

![](https://assets.leetcode.com/uploads/2018/12/13/160_statement.png)

begin to intersect at node c1.

 

Example 1:

![](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:

![](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)

Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:

![](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

## 题解
### 算法分析
1. 设定nodeA、nodeB分别指向两个链表头指针
2. 计算两个链表的相差长度diff
3. 如果diff不为零，则通过这个长度将nodeA或nodeB前进diff个节点，使得两个节点与尾节点的距离相等
4. nodeA、nodeB同步前进，每次前进一步，判断两个节点是否相等，如果相等输出节点，否则直到为空，输出NLL
### 复杂度分析
+ 时间复杂度: O(n)，n为两个链表长度的最大值
+ 空间复杂度：O(1)
### 源码
```C++ []
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        int sizeA = 0;
        while (nodeA != NULL)
        {
            nodeA = nodeA->next;
            ++sizeA;
        }

        ListNode *nodeB = headB;
        int sizeB = 0;
        while (nodeB != NULL)
        {
            nodeB = nodeB->next;
            ++sizeB;
        }

        if (nodeA != nodeB)
            return NULL;

        nodeA = headA;
        nodeB = headB;
        if (sizeA > sizeB)
        {
            int diff = sizeA - sizeB;
            while (diff > 0)
            {
                nodeA = nodeA-> next;
                --diff;
            }
        }
        else if (sizeA < sizeB)
        {
            int diff = sizeB - sizeA;
            while (diff > 0)
            {
                nodeB = nodeB->next;
                --diff;
            }            
        }

        while (nodeA != NULL && nodeB != NULL)
        {
            if (nodeA == nodeB)
                return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return NULL;
    }
};