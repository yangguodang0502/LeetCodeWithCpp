#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        unordered_set<int> numSet;
        for (auto &&i : nums1)
        {
            if (numSet.find(i) == numSet.end())
                numSet.insert(i);
        }
        
        vector<int> result;
        for (auto &&i : nums2)
        {
            if (numSet.find(i) != numSet.end())
            {
                numSet.erase(i);
                result.push_back(i);
            }
        }
        
        return result;
    }
};