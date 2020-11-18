#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpi10 = 0;
        int dpi11 = INT_MIN;
        int dpi20 = 0;
        int dpi21 = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            dpi20 = max(dpi20, dpi21 + prices[i]);
            dpi21 = max(dpi21, dpi10 - prices[i]);
            dpi10 = max(dpi10, dpi11 + prices[i]);
            dpi11 = max(dpi11, -prices[i]);
        }        
        return dpi20;
    }
};