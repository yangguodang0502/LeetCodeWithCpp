#  Reverse Linked List II
## 题目
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

## 题解
### 算法分析
1. 使用递归方式
2. reverseN(head, n):
3.  if (n==1) 
        tmp = head->next 
        return head
4.  last = reverseN(head->next, n-1)
5.  head->next->next = null
6.  head->next = tmp
7.  return last
8. reverseBetween(head, l, r)
9.  if (l==1)
        return reverseN(head, r)
10. head->next = reverseBetween(head->next, l-1, r-1)
11. return head
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    ListNode* tmp;

    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            tmp = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = tmp;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
};