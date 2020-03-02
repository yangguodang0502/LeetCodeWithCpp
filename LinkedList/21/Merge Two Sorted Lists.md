# 合并两个有序链表
## 题目
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

## 题解
### 算法分析
1. 使用双指针和递归
2. 当l1为空，返回l2
3. 当l2为空，返回l1
4. 当l1值小于等于l2值，合并l1->next和l2，并将结果赋给l1->next
5. 反之则合并l2->next和l1，并将结果赋给l2->next
### 复杂度分析
+ 时间复杂度: O(n), n为链表l1和l2的最短长度
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};