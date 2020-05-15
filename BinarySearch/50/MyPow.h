class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        return N >= 0 ? mult(x, N) : 1.0 / mult(x, -N);
    }

    double mult(double x, long n) {
        double ret = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1) 
            {
                ret *= x;
            }
            x *= x;
            n /= 2;
        }
        return ret;
    }
};