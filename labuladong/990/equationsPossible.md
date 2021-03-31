# Satisfiability of Equality Equations
## 题目
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

 

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true
 

Note:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] and equations[i][3] are lowercase letters
equations[i][1] is either '=' or '!'
equations[i][2] is '='

## 题解
### 解题思路
1. 构造uf一维数组，用于存储字母间的连接关系
2. 遍历equations，连接等式两边的字母
3. 遍历equations，判断不等式两边的字母是否连接，如果是则返回false
4. 返回true
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 代码

```cpp
class UF {
private:
    int count;
    vector<int> parent;
    vector<int> size;
public:
    UF(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void connect(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }

        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }

        count--;
    }

    bool connected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        return rootX == rootY;
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                uf.connect(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!') {
                if (uf.connected(equations[i][0] - 'a', equations[i][3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};