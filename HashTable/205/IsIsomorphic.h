#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> sHasMap;
        unordered_map<char, int> tHasMap;

        for (int i = 0; i < s.size(); i++)
        {
            if (sHasMap.count(s[i]) > 0 && tHasMap.count(t[i]) > 0)
            {
                if (sHasMap[s[i]] != tHasMap[t[i]])
                    return false;
            }
            else if (sHasMap.count(s[i]) > 0 || tHasMap.count(t[i]) > 0)
            {
                return false;
            }
            else
            {
                sHasMap[s[i]] = i;
                tHasMap[t[i]] = i;
            }
        }
        
        return true;
    }
};