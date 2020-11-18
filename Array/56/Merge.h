#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merges;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (merges.empty() || merges.back()[1] < intervals[i][0]) {
                merges.push_back(intervals[i]);
            }
            else {
                merges.back()[1] = max(merges.back()[1], intervals[i][1]);
            }
        }

       return merges; 
    }
};