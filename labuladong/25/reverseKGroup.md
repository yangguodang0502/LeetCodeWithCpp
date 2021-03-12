#  Reverse Nodes in k-Group
## 题目
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz

## 题解
### 算法分析
1. 定义函数实现翻转区间[a,b): reverse(a, b) 
2. 递归调用reverseKGroup, base case: 剩余元素个数小于k则返回head
3. a = head, b = head+k
4. 调用reverse(a, b) 返回newHead
5. a->next = reverseKGroup(b, k)
6. 返回newHead
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        ListNode* next = a;
        while (cur != b)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b = head;
        for (int i = 0; i < k; i++)
        {
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};