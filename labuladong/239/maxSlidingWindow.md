#  滑动窗口最大值
## 题目
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

## 题解
### 算法分析
1. 使用单调队列，push的时候将低于该值的都移除保持队首元素为最大值，pop的时候将队首元素移除
2. 遍历数组，i=0：n-1
3. 如果i<k-1，元素入队
4. 否则将i元素入队，并记录最大值，再将i-k元素出队
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class MonotanicQueue {
private:
    list<int> nums;
public:
    void push(int v) {
        while (!nums.empty() && nums.back() < v) {
            nums.pop_back();
        }
        nums.push_back(v);
    }

    void pop(int v) {
        if (v == nums.front()) {
            nums.pop_front();
        }
    }

    int max() {
        return nums.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        MonotanicQueue q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k-1) {
                q.push(nums[i]);
            } else {
                q.push(nums[i]);
                ret.push_back(q.max());
                q.pop(nums[i+1-k]);
            }
        }
        return ret;
    }
};