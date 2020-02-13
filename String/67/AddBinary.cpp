#include <string>

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();

        if (m < n)
            return addBinary(b, a);

        string c(a);
        int sum = 0;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0)
        {
            if (a[i] == '1')
                ++sum;
            if (j >= 0 && b[j--] == '1')
                ++sum;
            c[i] = sum % 2 == 1 ? '1' : '0';
            sum /= 2;
            --i;
        }
        
        if (sum == 1)
            c.insert(0, "1");
        
        return c;
    }
};