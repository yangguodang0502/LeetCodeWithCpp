# 两数之和 II - 输入有序数组
## 题目
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

## 题解
### 算法分析
1. 公式：
        while left < right do
            if numbers[left] + numbers[right] > target then --right
            elseif numbers[left] + numbers[right] < target then ++left
            else numbers[left] + numbers[right] == target then return [left,right]
        end
2. 假设left = 0, right = numbers.size()-1, 遍历numbers
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
            {
                --right;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                break;
            }
        }
        return ret;
    }
};