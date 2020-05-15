#  Pow(x, n)
## 题目
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

## 题解
### 算法分析
1. 定义函数mult(x,n)，初始化返回值为ret=1.0，遍历n直到为0
2. 根据n的二进制，判断当前位是否为1，如果为1将ret乘上x
3. x累乘，n二进制位右移
4. 如果n<0转化为求解1.0/mult(x, -n)
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        return N >= 0 ? mult(x, N) : 1.0 / mult(x, -N);
    }

    double mult(double x, long n) {
        double ret = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1) 
            {
                ret *= x;
            }
            x *= x;
            n /= 2;
        }
        return ret;
    }
};