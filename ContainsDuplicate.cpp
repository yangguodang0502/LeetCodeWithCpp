#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet;
        for (auto num:nums)
        {
            if (numSet.find(num) != numSet.end())
                return true;
            numSet.insert(num);
        }
        return false;
    }
};