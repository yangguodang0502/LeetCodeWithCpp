# 两个列表的最小索引总和
## 题目
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

## 题解
### 算法分析
1. 使用哈希表记录list1的字符串对应的下标
2. 定义最小下标和，初始化为两个字符串数组大小之和
3. 遍历list2，str=list2[i]，判断哈希表是否存在str
4. 如果存在判断下标之和与最小下标和的大小
5. 如果相等则将str加入结果数组
6. 否则如果小于则更新最小下标和为当前下标之和并清空结果数组，并将str加入
7. 最后返回result
### 复杂度分析
+ 时间复杂度：O(n)，n字符串长度
+ 空间复杂度：O(n)，哈希表占用额外空间
### 源码
```C++ []
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int size1 = list1.size();
        int size2 = list2.size();

        if (size1 == 0 || size2 == 0)
            return result;

        unordered_map<string, int> hasMap;
        int minIndexSum = size1 + size2;

        for (int i = 0; i < size1; i++)
        {
            hasMap.insert(make_pair(list1[i], i));
        }
        
        for (int i = 0; i < size2; i++)
        {
            string str = list2[i];
            if (hasMap.count(str))
            {
                int indexSum = hasMap[str] + i;

                if (indexSum == minIndexSum)
                {
                    result.push_back(str);
                }
                else if (indexSum < minIndexSum)
                {
                    minIndexSum = indexSum;
                    result.clear();
                    result.push_back(str);
                }
            }
        }

        return result;
    }
};