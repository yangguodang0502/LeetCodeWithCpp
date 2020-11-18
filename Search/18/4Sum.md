# 四数之和
## 题目
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
 

Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

## 题解
### 算法分析
1. 对数组进行排序
2. 遍历数组，锁定前两个元素，i=0:len-4, j=i+1:len-3
3. 使用双指针确定另外两个元素， l=j+1, r=len-1
4. 遍历l,r(l < r)，判断nums[i] + nums[j] + nums[l] + nums[r]与target的大小
5. 如果相等，则加入结果数组
### 复杂度分析
+ 时间复杂度：O(n^3)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 4)
            return ret;

        sort(nums.begin(), nums.end());

        int i, j, l, r;
        for (i = 0; i <= len - 4; i++)
        {          
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (j = i + 1; j <= len - 3; j++)
            {           
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                l = j + 1;
                r = len - 1;
                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                    {
                        r--;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                    {
                        l++;
                    }
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1])
                        {
                            r--;
                        }                        
                        l++;
                        r--;
                    }                    
                }                
            }
        }

        return ret;
    }
};