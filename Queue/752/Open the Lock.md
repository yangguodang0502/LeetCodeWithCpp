# 旋转链表
## 题目
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.

## 题解
### 算法分析
1. 使用广度优先搜索，定义哈希表ends存储deadends中的字符串
2. 定义哈希表visited存储访问过的字符串，定义num=0用于统计需要多少次转换
3. 定义队列queue，将0000加入队列，将空字符串入队用于判断是否累加转换次数num
4. 遍历队列直到为空，出队字符串node
5. 如果node==""，num累加，判断队列不为空，则加空字符串到队尾
6. 如果node==target，返回num
7. 如果ends不包含node，遍历字符串四个位置加减一对应的8个相邻节点，如果不在visited，将其加入visted和queue
### 复杂度分析
+ 时间复杂度：O(d + n^2*a^n)，d表示deadends.size()，a表示数组的个数，n表示字符串长度
+ 空间复杂度：O(d + a^n)
### 源码
```C++ []
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> ends;
        for (auto end : deadends)
        {
            ends.insert(end);
        }       

        string startNode = "0000";
        if (ends.find(startNode) != ends.end())
            return -1;

        set<string> visited;
        int num = 0;

        queue<string> queue;
        queue.push(startNode);
        queue.push("");

        while (!queue.empty())
        {
            string node = queue.front();
            queue.pop();
            
            if (node == "")
            {
                ++num; 

                if (!queue.empty())
                    queue.push("");
            }
            else if (node == target)
            {
                return num;
            }
            else if (ends.find(node) == ends.end())
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = -1; j <= 1; j += 2)
                    {
                        int val = ((node.at(i) - '0') + j + 10) % 10;
                        string str = node;
                        str[i] = '0' + val;

                        if (visited.find(str) == visited.end())
                        {
                            visited.insert(str);
                            queue.push(str);
                        }
                    }
                }               
            }            
        }
        
        return -1;
    }
};