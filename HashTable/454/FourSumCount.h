#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hashMap;
        int result = 0;

        for (auto &&a : A)
        {
            for (auto &&b : B)
            {
                hashMap[0-a-b]++;
            }
        }
        
        for (auto &&c : C)
        {
            for (auto &&d : D)
            {
                if (hashMap.count(c+d))
                    result += hashMap[c+d];
            }
        }

        return result;
    }
};