# Next Greater Element I
## 题目
You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.

Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, return -1 for this number.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation:
For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
For number 1 in the first array, the next greater number for it in the second array is 3.
For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation:
For number 2 in the first array, the next greater number for it in the second array is 3.
For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
 

Follow up: Could you find an O(nums1.length + nums2.length) solution?

## 题解
### 解题思路
1. 使用栈s存储当前元素，使用字典m记录结果
2. 从尾到头遍历nums2
3. 遍历栈，如果栈顶元素小于等于当前元素nums2[i]，则将栈顶出栈
4. 判断栈是否为空，如果为空则m[nums2[i]]=-1，否则m[nums2[i]]=s.top
5. 将当前元素入栈
6. 遍历nums1，将元素作为key，从字典中取值赋值给结果数组
7. 返回结果数组
### 复杂度分析
+ 时间复杂度：O(n+m)
+ 空间复杂度：O(n)
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res (nums1.size(), -1);

        stack<int> s;
        unordered_map<int, int> m;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            m[nums2[i]] = s.empty() ? - 1 : s.top();
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }

        return res;
    }
};