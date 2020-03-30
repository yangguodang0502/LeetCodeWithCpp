# ֻ����һ�ε�����
## ��Ŀ
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1


Example 2:
Input: [4,1,2,1,2]
Output: 4

## ���
### �㷨����
1. �����ϣ�����ڴ洢���ظ���Ԫ��
2. ����nums�����Ԫ�ز������ڹ�ϣ��������ϣ������ӹ�ϣ����ɾ��
3. �����������ع�ϣ�����Ԫ��
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)��nΪnums��С
+ �ռ临�Ӷȣ�O(n), ��ϣ��ռ�õĿռ�
### Դ��
```C++ []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = numSet.find(nums[i]);
            if (iter == numSet.end())
                numSet.insert(nums[i]);
            else
                numSet.erase(iter);
        }
        return *numSet.begin();
    }
};