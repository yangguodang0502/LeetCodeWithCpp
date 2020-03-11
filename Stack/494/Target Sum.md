# Ŀ���
## ��Ŀ
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

## ���
### �㷨����
1. ʹ�ö�̬�滮��ת��Ϊ01��������
2. ����sum��ʾnums�ܺͣ���S > sumʱ�޽⣬����0
3. ����sumP��ʾ�����ͣ�sumN��ʾ������
4. ����sumP - sumN = S, sump + sumN = sum�ɵ�2*sumP = S + sum
5. ���Ե�(S + sum) % 2 != 0ʱ�޽⣬����0
6. sumP = (S+sum)/2
7. ��������dp[sumP+1]���ڴ洢������ΪsumP�Ľ��, dp[0] = 1
8. ����nums, num : nums
9. ����dp, i = sumP : num : --
10. dp[i] += dp[i - num]
11. ��󷵻�dp[sumP]
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n*sumP), n = nums.size()
+ �ռ临�Ӷȣ�O(sumP)
### Դ��
```C++ []
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;

        for (const auto &num : nums)
            sum += num;
        
        if (S > sum)
            return 0;
        
        S += sum;
        if (S % 2 != 0)
            return 0;

        int sumP = S / 2;
        vector<int> dp(sumP+1, 0);
        dp[0] = 1;

        for (const auto &num : nums)
        {
            for (int i = sumP; i >= num; i--)
            {
                dp[i] += dp[i - num];
            }            
        }
        
        return dp[sumP];
    }
};