// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = -1;
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(left))
            {
                return left;
            }
            else if (isBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return ans;
    }
};