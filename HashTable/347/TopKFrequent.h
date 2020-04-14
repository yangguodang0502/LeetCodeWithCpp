#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto &&num : nums)
        {
            hashMap[num]++;
        }        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        for (auto &&it : hashMap)
        {
            if (priorityQueue.size() == k)
            {
                if (it.second > priorityQueue.top().first)
                {
                    priorityQueue.pop();
                    priorityQueue.push(make_pair(it.second, it.first));
                }                
            }
            else
            {
                priorityQueue.push(make_pair(it.second, it.first));
            }            
        }
        
        vector<int> result;
        while (!priorityQueue.empty())
        {
            result.push_back(priorityQueue.top().second);
            priorityQueue.pop();
        }
        
        return result;
    }
};