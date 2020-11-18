#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ret;
        unordered_map<char, int> hashMap;
        priority_queue<pair<int, char>> pq;
        for (auto& it:s)
        {
            hashMap[it]++;
        }
        for (auto& it:hashMap)
        {
            pq.push(make_pair(it.second, it.first));
        }
        while (!pq.empty())
        {
            auto it = pq.top();
            int num = it.first;
            char ch = it.second;
            while (num--)
            {
                ret += ch;
            }
            pq.pop();
        }
        return ret;        
    }
};