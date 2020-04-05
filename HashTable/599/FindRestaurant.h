#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int size1 = list1.size();
        int size2 = list2.size();

        if (size1 == 0 || size2 == 0)
            return result;

        unordered_map<string, int> hasMap;
        int minIndexSum = size1 + size2;

        for (int i = 0; i < size1; i++)
        {
            hasMap.insert(make_pair(list1[i], i));
        }
        
        for (int i = 0; i < size2; i++)
        {
            string str = list2[i];
            if (hasMap.count(str))
            {
                int indexSum = hasMap[str] + i;

                if (indexSum == minIndexSum)
                {
                    result.push_back(str);
                }
                else if (indexSum < minIndexSum)
                {
                    minIndexSum = indexSum;
                    result.clear();
                    result.push_back(str);
                }
            }
        }

        return result;
    }
};