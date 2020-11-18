#  替换空格
## 题目
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

## 题解
### 算法分析
1. 遍历字符串，统计空格的个数
2. 根据空格的个数计算填充后的字符串长度newLen
3. 将字符串的大小设置成新的长度newLen
4. 从尾到头遍历字符串，当字符等于空格将02%依次填入尾部，否则将字符填入尾部
5. 返回字符串
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (auto &&ch : s)
        {
            if (ch == ' ')
            {
                count++;
            }          
        }

        int len = s.length();
        int newLen = len + 2*count;
        s.resize(newLen);
        for (int i = len - 1, j = newLen - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (ch == ' ')
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else
            {
                s[j--] = ch;
            }
        }
        
        return s;
    }
};