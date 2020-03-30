#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = numSet.find(nums[i]);
            if (iter == numSet.end())
                numSet.insert(nums[i]);
            else
                numSet.erase(iter);
        }
        return *numSet.begin();
    }
};