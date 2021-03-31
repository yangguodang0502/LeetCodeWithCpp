#include <vector>
#include <string>

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