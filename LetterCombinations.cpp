#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letterMap[] = {
            "",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
        };

        vector<string> res;
        if (digits == "")
            return res;
        findCombination(digits, 0, "", res, letterMap);
        return res;
    };

    void findCombination(string digits, int index, string str, vector<string>& res, string letterMap[])
    {
        if (index == digits.length())
        {
            res.push_back(str);
            return;
        }

        char ch = digits.at(index);
        string letters = letterMap[ch - '0'];
        for (int i = 0; i < letters.length(); ++i)
        {
            findCombination(digits, index + 1, str + letters.at(i), res, letterMap);
        }
    }
};