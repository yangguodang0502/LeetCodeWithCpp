#include <vector>
#include <stack>

using namespace std;

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