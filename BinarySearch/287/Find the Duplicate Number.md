#  寻找重复数
## 题目
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

## 题解
### 算法分析
1. 问题可以转换为查找循环链表的环的首节点
2. 先用快慢指针找到相交点
3. 再将其中一个指针指向头节点
4. 同时移动两个指针直到相遇即为所求节点
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int first = nums[0];
        int second = nums[0];
        do
        {
            first = nums[first];
            second = nums[nums[second]];
        } while (first != second);
        
        second = first;
        first = nums[0];
        while (first != second)
        {
            first = nums[first];
            second = nums[second];
        }
        
        return first;
    }
};