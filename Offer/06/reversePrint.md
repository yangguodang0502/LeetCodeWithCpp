#  从尾到头打印链表
## 题目
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

## 题解
### 算法分析
1. 使用递归方法，遍历链表直到为空
2. 如果不为空继续遍历下一个节点，并把当前值加入数组
3. 递归结束，返回数组
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)，递归调用栈的空间消耗
### 源码
```C++ []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void recursiveNode(ListNode* node, vector<int>& ret) {
        if (node != NULL) {
            recursiveNode(node->next, ret);
            ret.push_back(node->val);
        }
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        recursiveNode(head, ret);
        return ret;
    }
};