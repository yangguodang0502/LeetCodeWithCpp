#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
            {
                --right;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                break;
            }
        }
        return ret;
    }
};