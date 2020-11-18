#include <vector>
#include <list>

using namespace std;

class MonotanicQueue {
private:
    list<int> nums;
public:
    void push(int v) {
        while (!nums.empty() && nums.back() < v) {
            nums.pop_back();
        }
        nums.push_back(v);
    }

    void pop(int v) {
        if (v == nums.front()) {
            nums.pop_front();
        }
    }

    int max() {
        return nums.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        MonotanicQueue q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k-1) {
                q.push(nums[i]);
            } else {
                q.push(nums[i]);
                ret.push_back(q.max());
                q.pop(nums[i+1-k]);
            }
        }
        return ret;
    }
};