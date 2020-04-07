#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string Hash(string str)
    {
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> hashMap;

        for (auto &&str : strs)
        {
            string hashStr = Hash(str);
            if (hashMap.count(hashStr))
            {
                result[hashMap[hashStr]].push_back(str);
            }
            else
            {
                vector<string> vec;
                vec.push_back(str);
                result.push_back(vec);
                
                hashMap.insert(make_pair(hashStr, result.size() - 1));
            }
        }

        return result;
    }
};