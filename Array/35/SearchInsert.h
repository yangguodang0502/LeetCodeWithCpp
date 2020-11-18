#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            if (target <= nums[low])
                return low;
            if (target > nums[high])
                return high + 1;
            else if (target == nums[high])
                return high;

            int mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};