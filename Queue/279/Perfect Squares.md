# 完全平方数
## 题目
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

## 题解
### 算法分析
1. 使用动态规划，创建数组a = int[n+1]
2. 遍历数组a，i = 1 ; i <= n; i++
3. a[i] = i，i表示最大的个数
4. 假设x=i-j*j>=0，动态转移方程：a[i] = min(a[i], a[x] + 1)
5. 遍历x，j = 1; x; j++，更新a[i]值
6. 返回a[n]
### 复杂度分析
+ 时间复杂度: O(n*sqrt(n))
+ 空间复杂度：O(n+1)
### 源码
```C++ []
class Solution {
public:
    int numSquares(int n) {
        int* a = new int[n + 1]();

        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            
            for (int j = 1; i - j * j >= 0; j++)
            {
                a[i] = min(a[i], a[i - j * j] + 1);
            }       
        }        

        int ret = a[n];
        delete[] a;
        return ret;
    }
};