# Russian Doll Envelopes
## 题目
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104

## 题解
### 解题思路
1. 先对宽度进行升序排序
2. 如果宽度相同，对高度进行降序排序
3. 将排序后的高度组成数组
4. 计算该数组的LIS并返回
### 复杂度分析
+ 时间复杂度：O(nlogn)
+ 空间复杂度：O(n)
### 代码

```cpp
bool compare(vector<int>& a, vector<int> b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> nums;
        for (int i = 0; i < envelopes.size(); i++) {
            nums.push_back(envelopes[i][1]);
        }
        return lengthOfLIS(nums);
    }

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