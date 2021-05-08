#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                count++;
                end = intervals[i][1];
            }
        }
        return count;
    }
};