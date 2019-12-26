#include <string>

using namespace std;

class Solution {
public:
    void reverseString(int head, int tail, string& s) {
        while (head < tail)
        {
            s[head] ^= s[tail];
            s[tail] ^= s[head];
            s[head++] ^= s[tail--];
        }
    }

    string reverseWords(string s) {
        int head = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                reverseString(head, i - 1, s);
                head = i + 1;
            }
        }
        reverseString(head, s.length() - 1, s);
        return s;
    }
};