#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res (nums1.size(), -1);

        stack<int> s;
        unordered_map<int, int> m;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            m[nums2[i]] = s.empty() ? - 1 : s.top();
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }

        return res;
    }
};