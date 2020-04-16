#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (rightIndex >= leftIndex)
        {
            int midIndex = (leftIndex + rightIndex) / 2;
            if (nums[midIndex] == target)
                return midIndex;
            else if (nums[midIndex] < target)
                leftIndex = midIndex + 1;
            else
                rightIndex = midIndex - 1;
        }
        
        return -1;
    }
};