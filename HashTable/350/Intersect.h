#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        unordered_map<int, int> hashMap;
        vector<int> result;

        for (auto &&num : nums1)
        {
            if (hashMap.count(num))
            {
                ++hashMap[num];
            }
            else
            {
                hashMap[num] = 1;
            }            
        }
        
        for (auto &&num : nums2)
        {
            auto iter = hashMap.find(num);
            if (iter != hashMap.end() && iter->second > 0)
            {
                --iter->second;
                result.push_back(num);
            }
        }
        
        return result;
    }
};