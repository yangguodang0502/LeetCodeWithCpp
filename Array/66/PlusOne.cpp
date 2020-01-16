#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output(digits.size(), 0);
        int flag = 1;

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int temp = digits[i] + flag;
            output[i] = temp % 10;
            flag = temp / 10;
        }

        if (flag != 0)
        {
            output.insert(output.begin(), flag);
        }

        return output;
    }
};