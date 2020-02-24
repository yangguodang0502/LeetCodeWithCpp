#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";
        
        string res = "";
        string tmp = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            bool addTmp = false;

            if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    addTmp = true;
                }
            }
            else
            {
                tmp = s[i] + tmp;

                if (i == 0)
                {
                    addTmp = true;
                }
            }

            if (addTmp)
            {
                if (!res.empty())
                    res += ' ';
                res += tmp;
                tmp = "";
            }
        }

        return res;
    }
};