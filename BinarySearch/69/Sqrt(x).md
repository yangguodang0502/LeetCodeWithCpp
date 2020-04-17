#  x的平方根
## 题目
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

## 题解
### 算法分析
1. 初始条件：left = 0,right = x,ans = 0
2. 终止条件：val == x or left > right, 其中mid = (left + right) / 2, val = mid * mid
3. 向左查找：right = mid - 1
4. 向右查找：left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)，n=x
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            long val = (long)mid * mid;

            if (val == x)
            {
                return mid;
            }
            else if (val < x)
            {
                ans = std::max(ans, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }            
        }
        
        return ans;
    }
};