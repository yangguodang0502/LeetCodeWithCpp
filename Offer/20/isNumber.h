#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        map<char, int> states[9] = {
            {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}},
            {{'d', 2}, {'.', 4}},
            {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}},
            {{'d', 3}, {'e', 5}, {' ', 8}},
            {{'d', 3}},
            {{'s', 6}, {'d', 7}},
            {{'d', 7}},
            {{'d', 7}, {' ', 8}},
            {{' ', 8}},
        };
        int p = 0;
        char t;
        for (auto &&c : s)
        {
            if (c == '+' || c == '-')
            {
                t = 's';
            }
            else if (c >= '0' && c <= '9')
            {
                t = 'd';
            }
            else if (c == 'e' || c == 'E')
            {
                t = 'e';
            }
            else if (c == '.' || c == ' ')
            {
                t = c;
            }
            else
            {
                t = '?';
            }
            map<char, int>::iterator it = states[p].find(t);
            if (it == states[p].end())
            {
                return false;
            }
            p = it->second;
        }
        return p == 2 || p == 3 || p == 7 || p == 8;  
    }
};