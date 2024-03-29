#  分割数组的最大值
## 题目
给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

## 题解
### 算法分析
1. 令left=max(nums),right=sum(nums)
2. 遍历left直到left>=right,令mid=(left+right)/2
3. 判断是否存在分割方案满足最大分割子数组和不超过mid
4. 如果存在则right=mid，否则left=mid+1
5. 返回left
+ 时间复杂度：O(nlog(right-left))，n为nums长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    bool exist(vector<int>& nums, int m, int x) {
        long long sum = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (sum + nums[i] > x) 
            {
                ++count;
                sum = nums[i];
            } 
            else 
            {
                sum += nums[i];
            }
        }
        return count <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0;
        long long right = 0;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (left < nums[i])
                left = nums[i];
            right += nums[i];
        }

        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (exist(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};