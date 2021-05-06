#include <vector>

using namespace std;

class Solution {
public:
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