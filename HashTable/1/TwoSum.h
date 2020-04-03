#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hasMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (hasMap.count(num) > 0)
            {
                result.push_back(hasMap[num]);
                result.push_back(i);
                return result;
            }
            else
            {
                int key = target - num;
                if (hasMap.count(key) <= 0)
                {
                    hasMap.insert(make_pair(key, i));
                }
            }
        }
        
        return result;
    }
};