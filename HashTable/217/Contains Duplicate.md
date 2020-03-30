# �����ظ�Ԫ��
## ��Ŀ
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true


## ���
### �㷨����
1. ʹ�ù�ϣ��洢�Ѿ����ʹ���Ԫ��
2. ����nums�������ϣ���д��ھͷ���true������Ԫ�ز����ϣ��
3. ������������false
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n)��nΪnums��С
+ �ռ临�Ӷȣ�O(n)����ϣ��ռ�ÿռ�
### Դ��
```C++ []
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet;
        for (auto num:nums)
        {
            if (numSet.find(num) != numSet.end())
                return true;
            numSet.insert(num);
        }
        return false;
    }
};