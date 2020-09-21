#  找出第 k 小的距离对
## 题目
给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。

提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

## 题解
### 算法分析
1. 从小到大排序nums
2. 假设low=0，high=nums[nums.size()-1]-nums[0]
3. 遍历low，high直到low==high
4. 假设mid=(low+high)/2,count=0,left=0
5. 遍历right=0:nums.size(),遍历left++直到nums[right]-nums[left]<=mid,count=right-left
6. 如果count>=k则high=mid，否则low=mid+1
7. 返回low
+ 时间复杂度：O(mlog(n)+mlog(m))，m为nums长度，n为nums元素之间的最大距离
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums[nums.size()-1] - nums[0];
        while (low < high)
        {
            int mid = (low + high) / 2;
            int count = 0;
            int left = 0;

            for (int right = 0; right < nums.size(); ++right)
            {
                while (nums[right]-nums[left] > mid)
                {
                    left++;
                }
                count += right - left;
            }

            if (count >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};