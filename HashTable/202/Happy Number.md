# 快乐数
## 题目
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example:
Input: 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

## 题解
### 算法分析
1. 定义递归函数用于解析n，哈希表作为参数存储待解析过的数
2. 如果n==1返回n，如果n存在于哈希表中即以解析过则返回n，否则将n加入哈希表
3. 定义数组nums用于存储n各个位数上的值
4. 遍历n直到为空，将n%10加入nums，n=n/10
5. 遍历nums,num in nums,计算n += num*num
6. 递归调用函数（n, nSet)
7. 主函数调用递归函数判断结果是否为1
### 复杂度分析
+ 时间复杂度：O(n)，n为分解次数
+ 空间复杂度：O(n), 哈希表和递归调用栈占用的空间

### 源码
```C++ []
class Solution {
public:
    int clacRecursive(int n, unordered_set<int>& nSet) {
        if (n == 1)
            return n;
        
        if (nSet.find(n) != nSet.end())
            return n;

        nSet.insert(n);
        vector<int> nums;

        while (n > 0)
        {
            nums.push_back(n % 10);
            n = n / 10;
        }        

        for (auto &&num : nums)
        {
            n += num * num;
        }
        
        return clacRecursive(n, nSet);
    }

    bool isHappy(int n) {
        unordered_set<int> nSet;
        return clacRecursive(n, nSet) == 1;
    }
};