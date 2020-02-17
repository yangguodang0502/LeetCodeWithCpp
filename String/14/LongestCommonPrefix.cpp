#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0)
            return "";

        string prefix = strs[0];
        for (int i = 1; i < size; i++)
        {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix == "")
                return "";
        }

        return prefix;
    }

    string commonPrefix(string left, string right) {
        int minSize = min(left.size(), right.size());
        
        for (int i = 0; i < minSize; i++)
        {
            if (left[i] != right[i])
                return left.substr(0, i);
        }
        
        return left.substr(0, minSize);
    }
};