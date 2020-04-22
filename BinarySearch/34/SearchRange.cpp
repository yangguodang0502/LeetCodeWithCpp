#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange {-1, -1};
        
        int leftIndex = findIndex(nums, target, true);
        if (leftIndex == nums.size() || nums[leftIndex] != target)
        {
            return targetRange;
        }

        targetRange[0] = leftIndex;
        targetRange[1] = findIndex(nums, target, false) - 1;

        return targetRange;
    }

    int findIndex(vector<int>& nums, int target, bool isLeft)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (isLeft && nums[mid] == target))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
};