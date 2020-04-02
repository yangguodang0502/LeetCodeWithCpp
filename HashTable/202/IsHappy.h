#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int clacRecursive(int n, unordered_set<int>& nSet) {
        if (n == 1)
            return n;
        
        if (nSet.find(n) != nSet.end())
            return n;

        nSet.insert(n);
        vector<int> nums;

        while (n > 0)
        {
            nums.push_back(n % 10);
            n = n / 10;
        }        

        for (auto &&num : nums)
        {
            n += num * num;
        }
        
        return clacRecursive(n, nSet);
    }

    bool isHappy(int n) {
        unordered_set<int> nSet;
        return clacRecursive(n, nSet) == 1;
    }
};