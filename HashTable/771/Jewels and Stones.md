#  宝石与石头
## 题目
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

## 题解
### 算法分析
1. 定义哈希表存储J的字符，遍历字符串J，将字符加入哈希表
2. 定义count存储J中存在S中字符的个数，初始化0
3. 遍历字符串S，判断字符是否存在于哈希表，如果存在则count++
4. 返回count
### 复杂度分析
+ 时间复杂度：O(n)，字符串J和S最大的长度
+ 空间复杂度：O(n)，哈希表占用空间
### 源码
```C++ []
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hashSet;
        
        for (auto &&ch : J)
        {
            hashSet.insert(ch);
        }

        int count = 0;
        
        for (auto &&ch : S)
        {
            if (hashSet.count(ch))
            {
                count++;
            }
        }
        
        return count;
    }
};