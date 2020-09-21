#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<int>& nums, int m, int x) {
        long long sum = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (sum + nums[i] > x) 
            {
                ++count;
                sum = nums[i];
            } 
            else 
            {
                sum += nums[i];
            }
        }
        return count <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0;
        long long right = 0;
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (left < nums[i])
                left = nums[i];
            right += nums[i];
        }

        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (exist(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};