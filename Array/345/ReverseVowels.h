#include <string>

using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {
        int head = 0;
        int tail = s.length() - 1;
    
        while (head < tail)
        {
            while (head < tail && !isVowel(s[head]))
            {
                head++;
            }

            while (head < tail && !isVowel(s[tail]))
            {
                tail--;
            }
            
            if (head < tail)
            {
                swap(s[head], s[tail]);

                head++;
                tail--;
            }
        }
        
        return s;
    }
};