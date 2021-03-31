#include <vector>

using namespace std;

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