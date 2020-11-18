# 有效的字母异位词
## 题目
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

## 题解
### 算法分析
1. 使用哈希表记录字符出现的个数
2. 使用大顶堆记录个数对应的字符
3. 遍历大顶堆，将字符加入到输出字符串
4. 遍历结束，返回输出字符串
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    string frequencySort(string s) {
        string ret;
        unordered_map<char, int> hashMap;
        priority_queue<pair<int, char>> pq;
        for (auto& it:s)
        {
            hashMap[it]++;
        }
        for (auto& it:hashMap)
        {
            pq.push(make_pair(it.second, it.first));
        }
        while (!pq.empty())
        {
            auto it = pq.top();
            int num = it.first;
            char ch = it.second;
            while (num--)
            {
                ret += ch;
            }
            pq.pop();
        }
        return ret;        
    }
};