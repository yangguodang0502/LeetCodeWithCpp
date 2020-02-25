#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int i = 0;

        for (int j = 1; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        return i + 1;
    }
};