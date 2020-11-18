#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> tmpSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = nums[i] >= INT32_MIN + t ? nums[i] - t : INT32_MIN;
            auto s = tmpSet.lower_bound(tmp);
            tmp = nums[i] <= INT32_MAX - t ? nums[i] + t : INT32_MAX;
            if (s != tmpSet.end() && *s <= tmp)
                return true;

            tmpSet.insert(nums[i]);

            if (tmpSet.size() > k)
                tmpSet.erase(nums[i-k]);
        }
        return false;
    }
};