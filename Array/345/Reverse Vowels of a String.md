# 反转字符串中的元音字母
## 题目
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

## 题解
### 算法分析
1. 使用头尾指针head、tail分别指向字符串的首位元素
2. 移动头尾指针，直到head>=tail
3. 当指向的元素非元音时相应指针前进1
4. 交换两个元音并将两个指针前进1
5. 结束循环返回字符串s
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {
        int head = 0;
        int tail = s.length() - 1;
    
        while (head < tail)
        {
            while (head < tail && !isVowel(s[head]))
            {
                head++;
            }

            while (head < tail && !isVowel(s[tail]))
            {
                tail--;
            }
            
            if (head < tail)
            {
                swap(s[head], s[tail]);

                head++;
                tail--;
            }
        }
        
        return s;
    }
};