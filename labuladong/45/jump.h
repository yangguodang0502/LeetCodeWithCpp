#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int end = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};