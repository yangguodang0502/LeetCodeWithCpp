#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i+1] <= nums[i])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i+1);
    }

private:
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    void reverse(vector<int>& nums, int start)
    {
        int i = start;
        int j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i , j);
            i++;
            j--;
        }
    }
};