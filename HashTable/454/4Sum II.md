#  四数相加 II
## 题目
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

## 题解
### 算法分析
1. 定义哈希表存储前两个数组的元素和取负的值
2. 遍历前两个数组填充哈希表
3. 遍历后两个数组，判断数组之和是否在哈希表中
4. 如果是则将结果加上哈希表对应的值
5. 返回结果
### 复杂度分析
+ 时间复杂度：O(n^2)，n为数组长度
+ 空间复杂度：O(n^2)，哈希表占用空间
### 源码
```C++ []
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hashMap;
        int result = 0;

        for (auto &&a : A)
        {
            for (auto &&b : B)
            {
                hashMap[0-a-b]++;
            }
        }
        
        for (auto &&c : C)
        {
            for (auto &&d : D)
            {
                if (hashMap.count(c+d))
                    result += hashMap[c+d];
            }
        }

        return result;
    }
};