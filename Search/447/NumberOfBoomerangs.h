#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int distance(vector<int>& l, vector<int>& r) {
        return (l[0] - r[0]) * (l[0] - r[0]) + (l[1] - r[1]) * (l[1] - r[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> hashMap;
            for (int j = 0; j < points.size(); j++)
            {
                if (j == i)
                    continue;
                int dist = distance(points[i], points[j]);
                hashMap[dist]++;
            }
            for (auto &&kv : hashMap)
            {
                int n = kv.second;
                if (n >= 2)
                {
                    ret += n*(n-1);
                }
            }            
        }
        return ret;
    }
};