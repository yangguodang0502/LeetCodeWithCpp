#  第一个错误的版本
## 题目
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

## 题解
### 算法分析
1. 初始条件：left = 1,right = n,mid = left + (right - left) / 2
2. 终止条件：left > right or isBadVersion(left) == true
3. 向左查找：isBadVersion(mid) == true -> right = mid
4. 向右查找：isBadVersion(mid) == false -> left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int firstBadVersion(int n) {
        int ans = -1;
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(left))
            {
                return left;
            }
            else if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return ans;
    }
};