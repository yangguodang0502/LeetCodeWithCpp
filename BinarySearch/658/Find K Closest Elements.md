#  找到 K 个最接近的元素
## 题目
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104

## 题解
### 算法分析
1. 如果目标小于等于数组第一个元素，返回数组最前k个元素
2. 如果目标大于等于数组最后一个元素，返回数组最后k个元素
3. 二分查找到最接近x的元素的数组下标index
4. 使用双指针方法根据index向左右两边扩展直到左右间的区间大小为k为止
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        if (x <= arr[0])
        {
            ret.assign(arr.begin(), arr.begin() + k);
            return ret;
        }
        else if (x >= arr[arr.size() - 1])
        {
            ret.assign(arr.end() - k, arr.end());
            return ret;
        }
        else
        {
            int low = 0;
            int high = arr.size() - 1;
            int index = 0;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (arr[mid] == x)
                {
                    index = mid;
                    break;
                }
                else if (arr[mid] < x)
                {
                    if (arr[mid + 1] == x)
                    {
                        index = mid + 1;
                        break;
                    }
                    else if (arr[mid + 1] > x)
                    {
                        index = (arr[mid + 1] - x) < (x - arr[mid]) ? mid + 1 : mid;
                        break;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (arr[mid - 1] == x)
                    {
                        index = mid - 1;
                        break;
                    }
                    else if (arr[mid - 1] < x)
                    {
                        index = (arr[mid] - x) <= (x - arr[mid - 1]) ? mid : mid - 1;
                        break;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            
            int left = index - 1;
            int right = index + 1;
            while (right - left - 1 < k)
            {
                if (left < 0)
                {
                    right++;
                }
                else if (right >= arr.size())
                {
                    left--;
                }
                else if (x - arr[left] > arr[right] - x)
                {
                    right++;
                }
                else
                {
                    left--;
                }                
            }

            ret.assign(arr.begin() + left + 1, arr.begin() + right);
        }
        return ret;
    }
};