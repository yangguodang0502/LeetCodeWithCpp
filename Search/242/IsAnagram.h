#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() > t.length())
        {
            return isAnagram(t, s);
        }
        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.length(); i++)
        {
            if (hashMap.count(s[i]))
            {
                hashMap[s[i]]++;
            }
            else
            {
                hashMap[s[i]] = 1;
            }            
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (!hashMap.count(t[i]) || hashMap[t[i]] == 0)
            {
                return false;
            }
            else
            {
                hashMap[t[i]]--;
            }            
        }
        return true;
    }
};