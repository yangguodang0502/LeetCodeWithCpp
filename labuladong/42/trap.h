#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;
        
        int left = 0;
        int right = n-1;
        int lMax = 0;
        int rMax = 0;
        int res =0;

        while (left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);
            if (lMax < rMax) {
                res += lMax - height[left];
                left++;
            } else {
                res += rMax - height[right];
                right--;
            }
        }
        
        return res;
    }
};