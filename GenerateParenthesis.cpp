#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrace(int left, int right, int n, string& str, vector<string>& res)
    {
        if (left == n && right == n)
        {
            res.push_back(str);
            return;
        }

        if (left < n)
        {
            str += "(";
            backtrace(left + 1, right, n, str, res);
            str.pop_back();
        }

        if (right < left)
        {
            str += ")";
            backtrace(left, right + 1, n, str, res);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrace(0, 0, n, str, res);
        return res;
    }
};