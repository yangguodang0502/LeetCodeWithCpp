#  有效的完全平方数
## 题目
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

## 题解
### 算法分析
1. 初始条件：left = 2,right = num / 2,mid = left + (right - left) / 2,square=mid*mid
2. 终止条件：left > right or square == num
3. 向左查找：square > num -> right = mid - 1
4. 向右查找：square < num -> left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
            return true;

        long left = 2;
        long right = num / 2;
        
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            if (square == num)
            {
                return true;
            }
            else if (square > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return false;
    }
};