#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRecursive(nums, target, 0, nums.size() - 1);
    }

    int searchRecursive(vector<int>& nums, int target, int left, int right)
    {
        if (left > right)
            return -1;
        
        if (target == nums[left])
            return left;
        
        if (target == nums[right])
            return right;
        
        int mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;

        if (nums[left] < nums[mid])
        {
            if (target < nums[mid] && target > nums[left])
            {
                return searchRecursive(nums, target, left + 1, mid - 1);
            }
            else
            {
                return searchRecursive(nums, target, mid + 1, right - 1);
            }            
        }
        else
        {
            if (target > nums[mid] && target < nums[right])
            {
                return searchRecursive(nums, target, mid + 1, right - 1);
            }
            else
            {
                return searchRecursive(nums, target, left + 1, mid - 1);
            }  
        }        
    }
};