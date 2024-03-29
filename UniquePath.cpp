static int a[101][101] = {0};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        if (m == 2 && n == 2)
            return 2;
        if ((m == 3 && n == 2) || (m == 2 && n == 3))
            return 3;
        if (a[m][n] > 0)
            return a[m][n];
        a[m-1][n] = uniquePaths(m-1, n);
        a[m][n-1] = uniquePaths(m, n-1);
        a[m][n] = a[m-1][n] + a[m][n-1];
        return a[m][n];
    }
};