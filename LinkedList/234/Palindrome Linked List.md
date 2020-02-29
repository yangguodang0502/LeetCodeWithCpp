# 移动零
## 题目
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

## 题解
### 算法分析
1. 使用快慢指针找到中间节点，快慢指针同时从头结点出发，慢指针每次前进一步，
   快指针每次前进两步，知道快指针走到末尾
2. 将中间节点后的链表反转，再与前半部分链表节点一一比较，如果存在值不相等，
   则返回false，否则返回true
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    ListNode* findMidNode(ListNode* head)
    {
        ListNode* slowNode = head;
        ListNode* fastNode = head;

        while (fastNode->next != NULL && fastNode->next->next != NULL)
        {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        
        return slowNode;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        while (node != NULL)
        {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }      

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;

        ListNode* midNode = findMidNode(head);
        ListNode* secondNode = reverseList(midNode->next);
        ListNode* firstNode = head;

        while (secondNode != NULL)
        {
            if (secondNode->val != firstNode->val)
            {
                return false;
            }

            secondNode = secondNode->next;
            firstNode = firstNode->next;
        }
        
        return true;
    }
};