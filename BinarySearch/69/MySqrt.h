#include <algorithm>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            long val = (long)mid * mid;

            if (val == x)
            {
                return mid;
            }
            else if (val < x)
            {
                ans = std::max(ans, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }            
        }
        
        return ans;
    }
};