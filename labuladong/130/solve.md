# Surrounded Regions
## 题目
Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

## 题解
### 解题思路
1. 构造uf一维数组，长度为m*n+1，用于存储与边缘有关联的O
2. uf[m*n]存放根节点dummy
3. 逐行遍历二维数组，判断首末列是否存在O，如果有则与dummy连接
4. 逐列遍历二维数组，判断首末行是否存在O，如果有则与dummy连接
5. 逐行逐列遍历二维数组，判断四个方向上是否相邻的O，如果存在则与该节点连接
6. 逐行逐列遍历二维数组，将与dummy没有连接的O替换为X
### 复杂度分析
+ 时间复杂度：O(m*n)
+ 空间复杂度：O(m*n)
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
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        UF uf(m * n + 1);
        int dummy = m * n;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                uf.connect(i * n, dummy);
            }
            if (board[i][n-1] == 'O') {
                uf.connect(i * n + n - 1, dummy);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                uf.connect(i, dummy);
            }
            if (board[m-1][i] == 'O') {
                uf.connect((m - 1) * n + i, dummy);
            }
        }
        vector<vector<int>> ds {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < ds.size(); k++) {
                        int x = i + ds[k][0];
                        int y = j + ds[k][1];
                        if (board[x][y] == 'O') {
                            uf.connect(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.connected(i * n + j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};