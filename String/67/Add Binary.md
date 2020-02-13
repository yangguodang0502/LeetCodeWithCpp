# 二进制求和
## 题目
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

## 题解
### 算法分析
1. 公式：sum = sum + a[index] + b[index], c[index] = sum % 2, sum /= 2
2. 从尾到头遍历字符串，按位求和，填充到结果字符串，最后判断是否
### 复杂度分析
+ 时间复杂度：O(max(m,n))，m为a长度，n为b长度
+ 空间复杂度：O(max(m,n))
### 源码
```C++ []
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();

        if (m < n)
            return addBinary(b, a);

        string c(a);
        int sum = 0;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0)
        {
            if (a[i] == '1')
                ++sum;
            if (j >= 0 && b[j--] == '1')
                ++sum;
            c[i] = sum % 2 == 1 ? '1' : '0';
            sum /= 2;
            --i;
        }
        
        if (sum == 1)
            c.insert(0, "1");
        
        return c;
    }
};