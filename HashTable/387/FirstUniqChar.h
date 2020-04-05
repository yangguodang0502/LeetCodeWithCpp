#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (hashMap.count(ch))
            {
                hashMap[ch] += 1;
            }
            else
            {
                hashMap.insert(make_pair(ch, 1));
            }            
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (hashMap[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};