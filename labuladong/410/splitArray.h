#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0;
        int high = 1;
        getMaxAndSum(nums, lo, high);

        while (lo < high)
        {
            int mid = lo + (high - lo) / 2;
            if (split(nums, mid) <= m)
            {
                high = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        
        return lo;
    }

    void getMaxAndSum(vector<int>& nums, int& max, int& sum) {
        for (auto &&i : nums)
        {
            if (max < i)
                max = i;
            sum += i;
        }
    }

    int split(vector<int>& nums, int max) {
        int count = 1;
        int sum = 0;
        for (auto &&i : nums)
        {
            if (sum + i > max) 
            {
                count++;
                sum = i;
            } 
            else
            {
                sum += i;
            }
        }
        return count;
    }
};