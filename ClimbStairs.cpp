class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        int* arr = new int[n+1]();
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; i++)   
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        int ret = arr[n];
        delete[] arr;
        return ret;
    }
};