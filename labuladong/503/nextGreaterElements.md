#  下一个更大元素 II
## 题目
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.

## 题解
### 算法分析
1. 使用单调栈，从尾到头遍历数组
2. 判断栈非空且栈顶元素小于当前元素，出栈
3. 判断栈非空则将栈顶元素加入结果数组，否则将-1加入结果数组
4. 最后一个元素需要循环寻找数组，可以采用复制数组接到数组后面，以求得最后一个元素的下一个更大元素
5. 可以采用下标通过求余的方式映射到原数组的下标来模拟循环数组，避免复制
+ 时间复杂度：O(n)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        stack<int> stackTemp;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stackTemp.empty() && stackTemp.top() <= nums[i % n]) {
                stackTemp.pop();
            }
            ret[i % n] = stackTemp.empty() ? -1 : stackTemp.top();
            stackTemp.push(nums[i % n]);
        }

        return ret;
    }
};