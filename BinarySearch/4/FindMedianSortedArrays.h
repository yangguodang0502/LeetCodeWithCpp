#include <vector>

using namespace std;

class Solution {
public:
    double getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;

        while (true)
        {
            if (idx1 == m)   
                return nums2[idx2 + k - 1];
            if (idx2 == n)
                return nums1[idx1 + k - 1];
            if (k == 1)
                return min(nums1[idx1], nums2[idx2]);
            
            int newIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, n - 1);
            int val1 = nums1[newIdx1];
            int val2 = nums2[newIdx2];
            if (val1 <= val2)
            {
                k -= newIdx1 - idx1 + 1;
                idx1 = newIdx1 + 1;
            }
            else
            {
                k -= newIdx2 - idx2 + 1;
                idx2 = newIdx2 + 1;
            }            
        }        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1)
        {
            return getKthElement(nums1, nums2, (len + 1) / 2);
        }
        else 
        {
            return (getKthElement(nums1, nums2, len / 2) + getKthElement(nums1, nums2, len / 2 + 1)) * 0.5f;
        }        
    }
};