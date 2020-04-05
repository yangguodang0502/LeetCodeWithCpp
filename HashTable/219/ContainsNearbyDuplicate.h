#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hashSet.count(nums[i]))
                return true;

            hashSet.insert(nums[i]);

            if (hashSet.size() > k)
                hashSet.erase(nums[i-k]);
        }
        return false;
    }
};