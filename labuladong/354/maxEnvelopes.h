#include <vector>
#include <algorithm>

using namespace std;

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