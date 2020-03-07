#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int* a = new int[n + 1]();

        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
            
            for (int j = 1; i - j * j >= 0; j++)
            {
                a[i] = min(a[i], a[i - j * j] + 1);
            }       
        }        

        int ret = a[n];
        delete[] a;
        return ret;
    }
};