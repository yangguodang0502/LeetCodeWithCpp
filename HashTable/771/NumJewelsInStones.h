#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hashSet;
        
        for (auto &&ch : J)
        {
            hashSet.insert(ch);
        }

        int count = 0;
        
        for (auto &&ch : S)
        {
            if (hashSet.count(ch))
            {
                count++;
            }
        }
        
        return count;
    }
};