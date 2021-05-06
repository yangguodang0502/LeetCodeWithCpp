# Longest Increasing Subsequence
## 题目
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up:

Could you come up with the O(n2) solution?
Could you improve it to O(n log(n)) time complexity?

## 题解
### 解题思路
1. 初始化牌堆数组tops，用于存储每个牌堆的堆顶元素，长度为nums长度
2. 初始化当前牌堆数heaps=0
3. 遍历nums数组，设当前牌num=nums[i]
4. 使用二分法查找插入位置，初始left=0，right=heaps，遍历left < right，
   设mid=(left+right)/2，如果tops[mid] < num，则left=mid+1，否则right=mid
5. 如果没找到合适的牌堆即left==heaps，则heaps+1
6. 将当前牌放到牌堆顶tops[left]=num
7. 遍历结束，返回heaps
### 复杂度分析
+ 时间复杂度：O(nlogn)
+ 空间复杂度：O(n)
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tops[nums.size()];
        int heaps = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            int left = 0;
            int right = heaps;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (tops[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (left == heaps) {
                heaps++;
            }
            
            tops[left] = num;
        }
        
        return heaps;
    }
};