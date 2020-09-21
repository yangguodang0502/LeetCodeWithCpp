# 验证回文串
## 题目
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

## 题解
### 算法分析
1. 使用头尾指针head、tail分别指向字符串的首位元素
2. 移动头尾指针，直到head>=tail结束循环返回true
3. 当指向的元素非ASCII码时相应指针加1
4. 否则当指向的元素相等时两个指针都加1
5. 否则结束循环返回false
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.length() - 1;
    
        while (head < tail)
        {
            while (head < tail && !isalnum(s[head]))
            {
                head++;
            }

            while (head < tail && !isalnum(s[tail]))
            {
                tail--;
            }
            
            if (head < tail)
            {
                if (tolower(s[head]) != tolower(s[tail]))
                {
                    return false;
                }

                head++;
                tail--;
            }
        }
        
        return true;
    }
};