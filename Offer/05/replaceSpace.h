#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (auto &&ch : s)
        {
            if (ch == ' ')
            {
                count++;
            }          
        }

        int len = s.length();
        int newLen = len + 2*count;
        s.resize(newLen);
        for (int i = len - 1, j = newLen - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (ch == ' ')
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else
            {
                s[j--] = ch;
            }
        }
        
        return s;
    }
};