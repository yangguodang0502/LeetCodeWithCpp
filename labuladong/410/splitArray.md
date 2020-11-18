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
1. 将问题转化为切分数组使得每个子集的和的不超过指定值的最小子集个数
2. 获取数组的最大值元素lo和数组元素之和high
3. 使用二分查找，遍历lo<high,若中间值mid对应的切分次数小于等于m,则收缩右区间，否则收缩左区间
4. 返回lo
+ 时间复杂度：O(nlogm)，n为nums长度，m为nums最大值元素和元素和的差
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0;
        int high = 1;
        getMaxAndSum(nums, lo, high);

        while (lo < high)
        {
            int mid = lo + (high - lo) / 2;
            if (split(nums, mid) <= m)
            {
                high = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        
        return lo;
    }

    void getMaxAndSum(vector<int>& nums, int& max, int& sum) {
        for (auto &&i : nums)
        {
            if (max < i)
                max = i;
            sum += i;
        }
    }

    int split(vector<int>& nums, int max) {
        int count = 1;
        int sum = 0;
        for (auto &&i : nums)
        {
            if (sum + i > max) 
            {
                count++;
                sum = i;
            } 
            else
            {
                sum += i;
            }
        }
        return count;
    }
};