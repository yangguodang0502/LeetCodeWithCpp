#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;
        int length = 0;
        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (hashMap.count(ch))
            {
                j = max(hashMap[ch], j);
            }

            length = max(length, i - j + 1);
            hashMap[ch] = i + 1;
        }
        
        return length;
    }
};