#include <string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenB = needle.length();
        if (lenB == 0)
            return 0;

        int lenA = haystack.length();
        for (int i = 0; i < lenA; ++i)
        {
            int len = lenA - i;
            if (len < lenB)
                return -1;

            int index = 0;
            while (index < lenB && haystack[i+index] == needle[index])
            {
                ++index;
            }
            
            if (index == lenB)
                return i;
        }

        return -1;
    }
};