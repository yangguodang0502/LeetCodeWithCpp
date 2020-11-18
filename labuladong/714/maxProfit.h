#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int count = prices.size();
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for (int i = 0; i < count; i++)
        {
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, temp - prices[i] - fee);
        }
        return dpi0;
    }
};