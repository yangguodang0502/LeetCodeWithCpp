#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> mCandidates;
    vector<int> mPath;
    vector<vector<int>> mRes;

public:
    void dfs(int start, int target)
    {
        if (target == 0)
        {
            mRes.push_back(mPath);
            return;
        }

        for (int i = start; i < mCandidates.size() && target - mCandidates[i] >= 0; ++i)
        {
            mPath.push_back(mCandidates[i]);
            dfs(i, target - mCandidates[i]);
            mPath.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        mCandidates = candidates; 
        sort(mCandidates.begin(), mCandidates.end());
        dfs(0, target);
        return mRes;
    }
};