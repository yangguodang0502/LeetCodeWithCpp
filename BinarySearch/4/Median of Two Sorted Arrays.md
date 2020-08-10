#  寻找两个正序数组的中位数
## 题目
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

## 题解
### 算法分析
1. 假设m=nums1.size(),n=nums2.size()
2. 当m+n是奇数时，中位数是第k=(m+n)/2个元素
3. 当m+n是偶数时，中位数是第k=(m+n)/2个元素和第k=(m+n)/2 + 1个元素的平均值
4. 当nums1[k/2 - 1]或者nums2[k/2 - 1]越界，取数组的最后一个元素
5. 当nums1或者nums2为空，取另一个数组的第k个元素
6. 当k=1，取两个数组首元素的最小值
7. 比较nums1[k/2 - 1]和nums2[k/2 - 1]的大小
8. 当nums1[k/2 - 1] <= nums2[k/2 - 1],排除nums1[0~k/2-1]
9. 当nums1[k/2 - 1] > nums2[k/2 - 1],排除nums2[0~k/2-1]
### 复杂度分析
+ 时间复杂度：O(log(m+n))
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    double getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;

        while (true)
        {
            if (idx1 == m)   
                return nums2[idx2 + k - 1];
            if (idx2 == n)
                return nums1[idx1 + k - 1];
            if (k == 1)
                return min(nums1[idx1], nums2[idx2]);
            
            int newIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, n - 1);
            int val1 = nums1[newIdx1];
            int val2 = nums2[newIdx2];
            if (val1 <= val2)
            {
                k -= newIdx1 - idx1 + 1;
                idx1 = newIdx1 + 1;
            }
            else
            {
                k -= newIdx2 - idx2 + 1;
                idx2 = newIdx2 + 1;
            }            
        }        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1)
        {
            return getKthElement(nums1, nums2, (len + 1) / 2);
        }
        else 
        {
            return (getKthElement(nums1, nums2, len / 2) + getKthElement(nums1, nums2, len / 2 + 1)) * 0.5f;
        }        
    }
};