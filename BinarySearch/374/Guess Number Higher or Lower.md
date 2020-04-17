#  猜数字大小
## 题目
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6

## 题解
### 算法分析x
1. 初始条件：left = 1,right = n
2. 终止条件：val == 0 or left > right, 其中mid = (left + right) / 2, val = guess(mid)
3. 向左查找：right = mid - 1
4. 向右查找：left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int val = guess(mid);
            if (val == 0)
            {
                return mid;
            }
            else if (val < 0)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return -1;
    }
};