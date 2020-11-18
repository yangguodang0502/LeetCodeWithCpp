#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        int dpPre0 = 0;
        for (int i = 0; i < count; i++)
        {
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, dpPre0 - prices[i]);
            dpPre0 = temp;
        }
        return dpi0;
    }
};