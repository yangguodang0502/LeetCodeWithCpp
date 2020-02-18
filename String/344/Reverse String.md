# 反转字符串
## 题目
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

## 题解
### 算法分析
1. 公式：swap(s[left++], s[right--])
2. 假设left = 0, right = s.size() - 1, 循环执行如上操作直到left >= right
### 复杂度分析
+ 时间复杂度：O(m)，m为s长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            
            ++left;
            --right;
        }
    }
};