#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) 
        {
            swap(nums1,nums2);
            return;
        }
        
        int a = m - 1;      //指向数组nums1未排序元素末尾
        int b = n - 1;      //指向数组nums2末尾
        int c = m + n - 1;  //指向数组nums1末尾
        
        while(a >= 0 && b >= 0)
        {
            nums1[c--] = (nums1[a] > nums2[b]) ? nums1[a--] : nums2[b--]; 
        }
        
        while(b >= 0)
            nums1[c--] = nums2[b--];        
    }
};